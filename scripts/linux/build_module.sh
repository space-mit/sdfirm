#!/bin/bash

TOP=`pwd`
SCRIPT=`(cd \`dirname $0\`; pwd)`
ARCH=riscv
HOSTNAME=sdfirm
BUILD_TINY=no
BUILD_LIB=yes
BUILD_SMP=yes
BUILD_NET=yes
BUILD_STO=no

if [ -z $BUSYBOX_DIR ]; then
	BUSYBOX_DIR=busybox
	BUSYBOX_PATH=$TOP/busybox
else
	BUSYBOX_PATH=`(cd $BUSYBOX_DIR; pwd)`
	BUSYBOX_DIR=`dirname $BUSYBOX_PATH`
fi
if [ -z $LINUX_DIR ]; then
	LINUX_DIR=linux
	LINUX_PATH=$TOP/linux
else
	LINUX_PATH=`(cd $LINUX_DIR; pwd)`
	LINUX_DIR=`dirname $LINUX_PATH`
fi
INITRAMFS_DIR=obj/initramfs/$ARCH
INITRAMFS_FILELIST=obj/initramfs/list-$ARCH
BBL_DIR=obj/bbl
ARCHIVES_DIR=$TOP/archive

function apply_modcfg()
{
	if [ "x$1" = "xlinux" ]; then
		dcfg=arch/$ARCH/configs/$2
	else
		dcfg=configs/$2
	fi
	mcfg=$SCRIPT/modcfg/$1/$3

	if [ -f $mcfg ]; then
		echo "Applying $1 modcfg $3..."
		$SDFIRM_PATH/scripts/modconfig.sh $2 $mcfg
		make oldconfig
		cp -f ./.config $dcfg
	fi
}

function clean_all()
{
	echo "== Clean all =="
	rm -rf $TOP/obj/busybox-$ARCH
	rm -rf $TOP/$INITRAMFS_DIR
	rm -rf $TOP/obj/linux-$ARCH
	rm -rf $TOP/$BBL_DIR
}

function build_busybox()
{
	echo "== Build Busybox =="
	rm -rf $TOP/obj/busybox-$ARCH
	(
	cd $BUSYBOX_PATH
	mkdir -pv $TOP/obj/busybox-$ARCH

	# Doing modcfgs in the original directory and save my_defconfig
	cp $SCRIPT/config/$BUSYBOX_CONFIG configs/my_defconfig
	if [ "xyes" = "x${BUILD_TINY}" ]; then
		apply_modcfg busybox my_defconfig e_tiny.cfg
	fi
	if [ "xno" = "x${BUILD_NET}" ]; then
		apply_modcfg busybox my_defconfig d_net.cfg
	fi
	# Starting the build process
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE \
		O=$TOP/obj/busybox-$ARCH/ my_defconfig
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE mrproper
	cd $TOP/obj/busybox-$ARCH
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE -j6
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE install
	)
}

build_initramfs_busybox()
{
	BUSYBOX_INSTALL=${TOP}/obj/busybox-${ARCH}/_install
	BUSYBOX_FILES=`ls ${BUSYBOX_INSTALL}$1`
	for f in ${BUSYBOX_FILES}; do
		if [ "$f" == "busybox" ]; then
			echo "file $1/busybox ${BUSYBOX_INSTALL}$1/busybox 755 0 0" >> $TOP/$INITRAMFS_FILELIST
			continue
		fi
		if [ -d ${BUSYBOX_INSTALL}$1/${f} ]; then
			echo "dir $1/${f} 755 0 0" >> $TOP/$INITRAMFS_FILELIST
			build_initramfs_busybox $1/$f
		else
			echo "slink $1/$f /bin/busybox 777 0 0" >> $TOP/$INITRAMFS_FILELIST
		fi
	done
}

install_initramfs_dir()
{
	echo "dir ${ROOTFS_TARGET} 755 0 0" >> $TOP/$INITRAMFS_FILELIST
}

install_initramfs_slink()
{
	echo "slink ${ROOTFS_TARGET} ${ROOTFS_HOST} 777 0 0" >> \
	       $TOP/$INITRAMFS_FILELIST
}

install_initramfs_file()
{
	echo "file ${ROOTFS_TARGET} ${ROOTFS_HOST} $1 0 0" >> \
		$TOP/$INITRAMFS_FILELIST
}

install_initramfs_lib()
{
	# TODO: Reduce Image Size
	#
	# Use ldd to reduce installed dependent libraries.
	echo "lib $1 $2"
}

install_initramfs_one()
{
	ROOTFS_HOST=$1$2
	ROOTFS_TARGET=$2
	if [ -d ${ROOTFS_HOST} ]; then
		install_initramfs_dir
		install_initramfs $1 ${ROOTFS_TARGET}
	else
		if [ -L ${ROOTFS_HOST} ]; then
			install_initramfs_slink
		else
			if [ -x ${ROOTFS_HOST} ]; then
				ROOTFS_LIBS=`ldd ${ROOTFS_HOST} | \
					sort | uniq | \
					awk -F\= '{print $2}' | \
					awk '{print $2}' | uniq`
				for ROOTFS_LIB in ${ROOTFS_LIBS} ; do
					install_initramfs_lib \
						$1 ${ROOTFS_LIB}
				done
				${CROSS_COMPILE}strip ${ROOTFS_HOST}
				install_initramfs_file 755
			else
				install_initramfs_file 644
			fi
		fi
	fi
}

install_initramfs()
{
	if [ -d $1$2 ]; then
		ROOTFS_FILES=`ls $1$2`
		for f in ${ROOTFS_FILES}; do
			install_initramfs_one $1 $2/${f}
		done
	else
		install_initramfs_one $1 $2
	fi
}

get_sysroot()
{
	GCC=`which ${CROSS_COMPILE}gcc`
	GCCDIR=`dirname $GCC`
	TOOLSDIR=`cd ${GCCDIR}/..; pwd`

	echo ${TOOLSDIR}/sysroot
}

function build_initramfs()
{
	echo "== Build initramfs =="

	echo "Installing initramfs..."
	rm -rf $TOP/$INITRAMFS_DIR
	mkdir -pv $TOP/$INITRAMFS_DIR
	cp -rf $SCRIPT/config/$INITRAMFS_FILELIST_TEMPLATE \
		$TOP/$INITRAMFS_FILELIST

	echo "Installing busybox..."
	cp -av $TOP/obj/busybox-$ARCH/_install/* $TOP/$INITRAMFS_DIR
	build_initramfs_busybox

	echo "Generating customizables..."
	rm -rf $TOP/obj/rootfs
	mkdir -p $TOP/obj/rootfs/etc
	echo $HOSTNAME > $TOP/obj/rootfs/etc/hostname

	# TODO: Smarter way to build rootfs
	# Currently we only lists files in config-initramfs-${ARCH}

	# Install non-customizables
	echo "Installing rootfs fixed ${SCRIPT}/rootfs..."
	install_initramfs ${SCRIPT}/rootfs
	#if [ "xno" != "x${BUILD_NET}" ]; then
	#	install_initramfs ${SCRIPT}/features/net
	#fi
	#if [ "xno" != "x${BUILD_STO}" ]; then
	#	install_initramfs ${SCRIPT}/features/sto
	#fi

	# Install customizables
	echo "Installing rootfs no-fixed ${TOP}/obj/rootfs..."
	install_initramfs ${TOP}/obj/rootfs

	# Copy libraries
	if [ "x${BUILD_LIB}" != "xno" ]; then
		SYSROOT=`get_sysroot`
		echo "Installing rootfs toolchain ${SYSROOT}..."
		install_initramfs ${SYSROOT} /sbin
		install_initramfs ${SYSROOT} /lib
		install_initramfs ${SYSROOT} /usr/bin/ldd
		install_initramfs ${SYSROOT} /usr/lib
	fi

	if [ -x $TOP/obj/bench ]; then
		echo "Installing rootfs testbench $TOP/obj/bench..."
		install_initramfs $TOP/obj/bench
	fi

	echo "Use INITRAMFS_SOURCE file list: $INITRAMFS_FILELIST"
	grep INITRAMFS_SOURCE $SCRIPT/config/$LINUX_CONFIG
	echo "So initramfs is built not here now but together with kernel later"
	cat $TOP/$INITRAMFS_FILELIST
}

function build_linux()
{
	echo "== Build Linux =="
	rm -rf $TOP/obj/linux-$ARCH
	#mkdir -p $TOP/obj/linux-$ARCH
	(
	cd $LINUX_PATH
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE distclean
	# Doing modcfgs in the original directory and save my_defconfig
	cp $SCRIPT/config/$LINUX_CONFIG arch/riscv/configs/my_defconfig
	if [ "xyes" = "x${BUILD_TINY}" ]; then
		apply_modcfg linux my_defconfig e_tiny.cfg
	fi
	if [ "xno" = "x${BUILD_SMP}" ]; then
		apply_modcfg linux my_defconfig d_smp.cfg
	fi
	if [ "xno" = "x${BUILD_NET}" ]; then
		apply_modcfg linux my_defconfig d_net.cfg
	fi
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE mrproper
	# Starting the build process
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE \
		O=$TOP/obj/linux-$ARCH/ my_defconfig
	ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE $LINUX_PATH/scripts/config \
		--file $TOP/obj/linux-$ARCH/.config \
		--set-str INITRAMFS_SOURCE $TOP/$INITRAMFS_FILELIST
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE \
		O=$TOP/obj/linux-$ARCH/ clean
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE \
		O=$TOP/obj/linux-$ARCH/ -j6
	if [ ! -f $TOP/obj/linux-$ARCH/vmlinux ]; then
		echo "Error: Failed to build Linux"
		exit 1
	fi
	${CROSS_COMPILE}objcopy \
		--only-keep-debug $TOP/obj/linux-$ARCH/vmlinux \
		$TOP/obj/linux-$ARCH/kernel.sym
	)
}

function build_sdfirm()
{
	echo "== Build sdfirm =="
	rm -rf $TOP/obj/sdfirm-$ARCH
	mkdir -p $TOP/obj/sdfirm-$ARCH
	(
	cd $SDFIRM_PATH
	if [ -x $TOP/obj/sdfirm-$ARCH ]; then
		make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE \
			O=$TOP/obj/sdfirm-$ARCH/ distclean
	fi
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE distclean
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE distclean
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE \
		O=$TOP/obj/sdfirm-$ARCH/ ${MACH}_bbl_defconfig
	ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPLE $SDFIRM_PATH/scripts/config \
		--file $TOP/obj/sdfirm-$ARCH/.config \
		--set-str SBI_PAYLOAD_PATH \
		$TOP/obj/linux-$ARCH/arch/$ARCH/boot/Image
	make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE \
		O=$TOP/obj/sdfirm-$ARCH/ -j6
	if [ ! -f $TOP/obj/sdfirm-$ARCH/sdfirm ]
	then
		echo "Error: Failed to build sdfirm"
		exit 1
	fi
	${CROSS_COMPILE}objcopy \
		--only-keep-debug $TOP/obj/sdfirm-$ARCH/sdfirm \
		$TOP/obj/sdfirm-$ARCH/sdfirm.sym
	)
}

function build_riscv-pk()
{
	echo "== Build riscv-pk =="
	rm -rf $TOP/$BBL_DIR
	mkdir -pv $TOP/$BBL_DIR
	(
	cd $BBL_DIR
	$SCRIPT/riscv-pk/configure \
		--enable-logo --host=riscv64-unknown-linux-gnu \
		--with-payload=$TOP/obj/linux-$ARCH/vmlinux
	make
	)
}

function build_bbl()
{
	if [ "x$BBL" = "xriscv-pk" ]; then
		build_riscv-pk
	fi
	if [ "x$BBL" = "xsdfirm" ]; then
		build_sdfirm
	fi
}

cd $TOP

usage()
{
	echo "Usage:"
	echo "`basename $0` [-m bbl] [-s] [-u] [-a] [-n hostname] [target]"
	echo "              [-d feat] [-e feat]"
	echo "Where:"
	echo " -m bbl:      specify rebuild of M-mode program"
	echo " -s:          specify rebuild of S-mode program"
	echo " -u:          specify rebuild of U-mode programs"
	echo " -a:          specify rebuild of all modes programs"
	echo " -n:          specify system hostname (default sdfirm)"
	echo " -d feat:     disable special features"
	echo "              feature includes:"
	echo "    shared:   shared library support"
	echo "    smp:      SMP support in OSen"
	echo "    network:  network and telnet login support"
	echo " -e feat:     enable special features"
	echo "              feature includes:"
	echo "    storage:  storage and NVME rootfs support"
	echo " target:      specify build type (default build)"
	echo "  build       build specified modules (default mode)"
	echo "  clean       build specified modules"
	exit $1
}

fatal_usage()
{
	echo $1
	usage 1
}

while getopts "ad:e:m:n:su" opt
do
	case $opt in
	a) M_MODE=yes
	   S_MODE=yes
	   U_MODE=yes;;
	d) if [ "x$OPTARG" = "xshared" ]; then
		BUILD_LIB=no
	   fi
	   if [ "x$OPTARG" = "xsmp" ]; then
		BUILD_SMP=no
	   fi
	   if [ "x$OPTARG" = "xnetwork" ]; then
		BUILD_NET=no
	   fi;;
	e) if [ "x$OPTARG" = "xtiny" ]; then
		BUILD_TINY=yes
	   fi
	   if [ "x$OPTARG" = "xstorage" ]; then
		BUILD_STO=yes
	   fi;;
	m) M_MODE=yes
	   BBL=$OPTARG;;
	n) HOSTNAME=$OPTARG;;
	s) S_MODE=yes;;
	u) U_MODE=yes;;
	?) echo "Invalid argument $opt"
	   fatal_usage;;
	esac
done
shift $(($OPTIND - 1))

if [ -z $CROSS_COMPILE ]; then
	CROSS_COMPILE=riscv64-unknown-linux-gnu-
fi
if [ -f $SCRIPT/config/config-busybox-$ARCH-$MACH ]; then
	BUSYBOX_CONFIG=config-busybox-$ARCH-$MACH
else
	BUSYBOX_CONFIG=config-busybox-$ARCH
fi
echo "Using busybox configuration ${BUSYBOX_CONFIG}..."
if [ -f $SCRIPT/config/config-linux-$ARCH-$MACH ]; then
	LINUX_CONFIG=config-linux-$ARCH-$MACH
else
	LINUX_CONFIG=config-linux-$ARCH
fi
echo "Using linux configuration ${LINUX_CONFIG}..."
INITRAMFS_FILELIST_TEMPLATE=config-initramfs-$ARCH

echo "== Prepare =="
if [ "x${M_MODE}" = "xyes" ]; then
	if [ -z $BBL ]; then
		BBL=riscv-pk
	fi
	if [ "x$BBL" = "xsdfirm" ]; then
		if [ -z $SDFIRM_DIR ]; then
			SDFIRM_DIR=sdfirm
			SDFIRM_PATH=$TOP/sdfirm
		else
			if [ ! -d $SDFIRM_DIR ]; then
				echo "Sdfirm source $SDFIRM_DIR not found"
				exit 1
			fi
			SDFIRM_PATH=`(cd $SDFIRM_DIR; pwd)`
			SDFIRM_DIR=`dirname $SDFIRM_PATH`
		fi
		if [ -z $MACH ]; then
			MACH=spike64
		fi
	fi
fi
if [ "x${S_MODE}" = "xyes" ]; then
	if [ ! -f $SCRIPT/config/$LINUX_CONFIG ]; then
		echo "Linux config not found $LINUX_CONFIG"
		exit 1
	fi
	if [ ! -d $LINUX_DIR ]; then
		echo "Linux source $LINUX_DIR not found"
		exit 1
	fi
fi
if [ "x${U_MODE}" = "xyes" ]; then
	if [ ! -f $SCRIPT/config/$BUSYBOX_CONFIG ]; then
		echo "Busybox config not found $BUSYBOX_CONFIG"
		exit 1
	fi
	if [ ! -d $BUSYBOX_DIR ]; then
		echo "Busybox source $BUSYBOX_DIR not found"
		exit 1
	fi
fi

if [ "x$1" = "xclean" ]; then
	clean_all
else
	if [ "x${U_MODE}" = "xyes" ]; then
		build_busybox
		build_initramfs
	fi
	if [ "x${S_MODE}" = "xyes" ]; then
		build_linux
	fi
	if [ "x${M_MODE}" = "xyes" ]; then
		build_bbl
	fi
fi
