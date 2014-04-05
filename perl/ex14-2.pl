#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex14-2.pl
#
#        USAGE: ./ex14-2.pl  
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
#      CREATED: 01/15/2014 05:21:45 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";


my %last_name = qw{
    fred flintstone wilma FlintStone Barney Rubble betty 
    rubble Bamm-Bamm Rubble Pebbles Flintstone
};

my @keys = sort {
    "\L$last_name{$a}" cmp "\L$last_name{$b}"
        or
    "\L$a" cmp "\L$b"
} keys %last_name;

foreach (@keys){
    print "$last_name{$_} , $_\n";
}

