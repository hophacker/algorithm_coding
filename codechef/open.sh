#!/bin/bash
if [ ${1} = ""]; then
    file=12
else
    file=${1}
fi
vim -p $file.cpp makefile in
