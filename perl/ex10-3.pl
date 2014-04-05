#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex10-3.pl
#
#        USAGE: ./ex10-3.pl  
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
#      CREATED: 01/14/2014 03:57:10 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";


my $length = 0;
foreach my $key(%ENV){
    my $l = length($key);
    $length = $l if $l > $length;
}

foreach my $key(sort keys %ENV){
    printf "%-${length}s %s\n", $key, $ENV{$key} // "{undefined}";
}
