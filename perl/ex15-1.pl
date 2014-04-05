#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex15-1.pl
#
#        USAGE: ./ex15-1.pl  
#
#  DESCRIPTION: guess a number
#
#      OPTIONS: ---
# REQUIREMENTS: ---
#         BUGS: ---
#        NOTES: ---
#       AUTHOR: Jie Feng (http://hey.i-feng.org), jokerfeng2010@gmail.com
# ORGANIZATION: 
#      VERSION: 1.0
#      CREATED: 01/16/2014 01:32:31 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature qw/state say switch/;

my $right = 0;
my $ans = int(1 + rand 100);

while(!$right){
    $num = <STDIN>;
    given ($num) {
        when ($num < $ans) {say "Too small!"}
        when ($num > $ans) {say "Too big!"}
        default {say "Bingo!"; $right = 1}
    }
}
