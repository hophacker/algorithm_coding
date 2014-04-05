#!/bin/bash - 
#===============================================================================
#
#          FILE: openBigInteger.sh
# 
#         USAGE: ./openBigInteger.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 12/25/2013 00:32
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

gvim -p BigInteger.cc BigInteger.h 
