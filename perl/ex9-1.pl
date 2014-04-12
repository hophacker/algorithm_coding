#!/usr/bin/env perl 
## Copyright (C) 2014 by Jie Feng Truly
#===============================================================================
#
#         FILE: ex9-1.pl
#
#        USAGE: ./ex9-1.pl  
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
#      CREATED: 01/12/2014 12:27:23 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";

my $what = "fred|barney";

while(<>){
    if (/($what){3}/){
        print
    }
}
