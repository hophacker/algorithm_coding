#!/bin/bash
if [ ${1} = ""]; then
    file=12
else
    file=${1}
fi
gvim -p $file.cc euler.cc euler.h  makefile
