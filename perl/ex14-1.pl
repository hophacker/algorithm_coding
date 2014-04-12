#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex14-1.pl
#
#        USAGE: ./ex14-1.pl  
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
#      CREATED: 01/15/2014 04:45:49 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";


my @numbers;
push @numbers, split while <>;

@numbers = sort {$a <=> $b} @numbers;
foreach(@numbers){
    printf "%20g\n", $_;
}
