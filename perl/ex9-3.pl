#!/usr/bin/env perl 
## Copyright (C) 2014 by Jie Feng Truly
#===============================================================================
#
#         FILE: ex9-3.pl
#
#        USAGE: ./ex9-3.pl  
#
#  DESCRIPTION: 
#
#      OPTIONS: ---
# REQUIREMENTS: ---
#         BUGS: ---
#        NOTES: ---
#       AUTHOR: Jie Feng (http://hey.i-feng.org), jokerfeng2010@gmail.com
# ORGANIZATION: 
#      VERSION: 1.0
#      CREATED: 01/12/2014 12:36:47 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";


$^I = ".bak";
while(<>){
    s/fred/\0/gi;
    s/wilma/Fred/gi;
    s/\0/Wilma/gi;
    print;
}
