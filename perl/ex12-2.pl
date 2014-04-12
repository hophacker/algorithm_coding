#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex12-2.pl
#
#        USAGE: ./ex12-2.pl  
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
#      CREATED: 01/14/2014 10:07:29 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";

die "No file names supplied!\n" unless @ARGV;
my $longestDays = -M shift @ARGV;
my $name = "";
foreach (@ARGV){
    my $days = -M;
    ($name, $longestDays) = ($_, $days)
        if $days > $longestDays;
}
printf "$name has the longest days since modified: %.1f days.\n", $longestDays;
