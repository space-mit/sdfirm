#!/bin/sh

SCRIPT=`(cd \`dirname $0\`; pwd)`
SDFIRM_ROOT=`(cd ${SCRIPT}/..; pwd)`
SDFIRM_NDA=`(cd .; pwd)`

UPDATE=no

walk_source_one()
{
	remotef=$1$3
	localf=$2$3
	sourcef=$3

	if [ -d $localf ]; then
		walk_source $1 $2 $3
	else
		if [ "x${UPDATE}" = "xyes" ]; then
			cp -f $localf $remotef
		else
			diff -u $localf $remotef
		fi
	fi
}

walk_source()
{
	localf=$2$3

	if [ -d $localf ]; then
		sourcef=`ls $localf`
		for f in $sourcef; do
			walk_source_one $1 $2 $3/$f
		done
	else
		walk_source_one $1 $2 $3
	fi
}

walk_source $SDFIRM_ROOT $SDFIRM_NDA
