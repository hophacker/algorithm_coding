#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex15-4.pl
#
#        USAGE: ./ex15-4.pl  
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
#      CREATED: 01/16/2014 03:30:28 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature qw/state say switch/;


my $favorite = 42;
sub divisors{
    my $number = shift;
    my @divisors = ();
    foreach my $divisor (2 .. $number /2){
        push @divisors, $divisor unless $number % $divisor;
    }
    return @divisors;
}

given ($ARGV[0]){
    when (!/^\d+$/) { say "Not a number!";continue;}
    my @divisors = &divisors($_);

    when (2 ~~ @divisors) {say "$_ is even"; continue;}
    when (!(2 ~~ @divisors)) {say "$_ is odd"; continue}

    when ($_ ~~ $favorite) {say "$_ is my favorite"; continue}
    when ($favorite ~~ @divisors) {
        say "$_ is divisable by my favorite"; continue
    }

    when (@divisors ~~ []) {say "The number is prime"}
    default {say "$_ is divisable by @divisors"}
}
