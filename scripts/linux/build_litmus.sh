#!/bin/sh
#
# Build litmus images to the bench folder.

TOP=`pwd`
SCRIPT=`(cd \`dirname $0\`; pwd)`
SRCDIR=`(cd ${SCRIPT}/..; pwd)`
WORKING_DIR=`(cd ${SCRIPT}/../../..; pwd)`

# Default options
LITMUS_REBUILD=no
LITMUS_ARCHIVE=no

usage()
{
	echo "Usage:"
	echo "`basename $0` [-a] [-r] [cores]"
	echo "Where:"
	echo " -a:          generate litmus source archive"
	echo " -r:          rebuild litmus binaries"
	echo "cores:        specify number of CPUs"
	exit $1
}

fatal_usage()
{
	echo $1
	usage 1
}

while getopts "ar" opt
do
	case $opt in
	a) LITMUS_ARCHIVE=yes;;
	r) LITMUS_REBUILD=yes;;
	?) echo "Invalid argument $opt"
	   fatal_usage;;
	esac
done
shift $(($OPTIND - 1))

LITMUS_CORES=$1
if [ "x${LITMUS_CORES}" = "x" ]; then
	LITMUS_CORES=4
fi
if [ -z ${LITMUS_ROOT} ]; then
	LITMUS_ROOT=${WORKING_DIR}/litmus-tests-riscv
fi
if [ -z ${CROSS_COMPILE} ]; then
	export CROSS_COMPILE=riscv64-unknown-linux-gnu-
fi
LITMUS_DIR=${TOP}/obj/bench/usr/local/bin
LITMUS_SHL=${LITMUS_DIR}/litmus.sh
LITMUS_ELF=${LITMUS_DIR}/litmus
LITMUS_SRCS=${LITMUS_ROOT}/litmus-${LITMUS_CORES}cores

if [ -d ${LITMUS_SRCS} ]; then
	# hw-tests-src extracted version
	echo "Generating ${LITMUS_CORES}cores litmus binary from source..."
	(
		cd ${LITMUS_SRCS}
		if [ "x${LITMUS_REBUILD}" = "xyes" ]; then
			make -f Makefile.litmus GCC=${CROSS_COMPILE}gcc \
				clean >/dev/null
		fi
		make -f Makefile.litmus GCC=${CROSS_COMPILE}gcc
	)
	LITMUS_TAR=no
	LITMUS_RUN=${LITMUS_SRCS}
else
	# git repository version
	echo "Generating ${LITMUS_CORES}cores litmus binary from repository..."
	(
		cd ${LITMUS_ROOT}
		if [ "x${LITMUS_REBUILD}" = "xyes" ]; then
			make hw-tests CORES=${LITMUS_CORES} \
				GCC=${CROSS_COMPILE}gcc clean >/dev/null
		fi
		make hw-tests CORES=${LITMUS_CORES} GCC=${CROSS_COMPILE}gcc
	)
	if [ "x${LITMUS_ARCHIVE}" = "xyes" ]; then
		LITMUS_TAR=yes
	fi
	LITMUS_RUN=${LITMUS_SRCS}/hw-tests
fi
mkdir -p ${LITMUS_DIR}
cp -f ${LITMUS_RUN}/run.exe ${LITMUS_ELF}
${CROSS_COMPILE}strip ${LITMUS_ELF}
cp -f ${LITMUS_RUN}/run.sh ${LITMUS_SHL}.0
sed "s/\.\/run\.exe/litmus/" ${LITMUS_SHL}.0 > ${LITMUS_SHL}.1
sed "s/> .*//" ${LITMUS_SHL}.1 > ${LITMUS_SHL}.2
mv -f ${LITMUS_SHL}.2 ${LITMUS_SHL}
rm -f ${LITMUS_SHL}.*
chmod +x ${LITMUS_SHL}

if [ "x${LITMUS_TAR}" = "xyes" ]; then
	echo "Generating ${LITMUS_CORES}cores litmus tarball..."
	rm -rf ${LITMUS_SRCS}
	mv ${LITMUS_ROOT}/hw-tests-src ${LITMUS_SRCS}
	(
		cd ${LITMUS_SRCS}
		make -f Makefile.litmus GCC=${CROSS_COMPILE}gcc clean >/dev/null
	)
	(
		cd ${LITMUS_ROOT}
		tar -zcf litmus-${cores}cores.tgz litmus-${cores}cores
	)
fi
