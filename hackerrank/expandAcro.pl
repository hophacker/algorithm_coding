#!/usr/bin/perl 
#===============================================================================
#
#         FILE:  expandAcro.pl
#
#        USAGE:  ./expandAcro.pl  
#
#  DESCRIPTION:  
#
#      OPTIONS:  ---
# REQUIREMENTS:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  Jie Feng (mn), jokerfeng2010@gmail.com
#      COMPANY:  The Johns Hopkins University
#      VERSION:  1.0
#      CREATED:  01/05/2014 12:06:05 AM
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;


my $n = <>;
my @line;
for (my $i = 0; $i < $n; $i++){
    $line[$i] = <>;
}
for (my $i = 0; $i < $n; $i++){
    my $w = <>;
    my @words = split(/[: ,.\n()]+/, $line[$i]);
    print $w;

    foreach my $val (@words){
       print "$val\n";
    }
}



