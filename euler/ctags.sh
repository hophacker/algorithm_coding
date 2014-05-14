#!/bin/sh

# ./ctags_with_dep.sh file1.c file2.c ... to generate a tags file for these files.

#$*
files="BigIntBase.cc BigIntBase.h testBigIntBase.cc"
g++ -M $files | sed -e 's/[\\ ]/\n/g' | \
        sed -e '/^$/d' -e '/\.o:[ \t]*$/d' | \
        ctags -L - --c++-kinds=+p --fields=+iaS --extra=+q
