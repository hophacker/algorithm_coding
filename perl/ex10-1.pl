#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex10-1.pl
#
#        USAGE: ./ex10-1.pl  
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
#      CREATED: 01/14/2014 02:54:59 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";

my $debug = $ENV{DEBUG} // 0;
my $num = int(1 + rand 100);

print "The secret is $num. \n" if $debug;
print "Guess a number between 1 - 100:\n";
while(<STDIN>){
    chomp $_;
    if (/exit|quit|^\s*$/i){
        last;
    }elsif(/[^\d]+/){
        print "The input format is not proper. Please enter again:\n";
    }else{
        $guess = $_;
        if ($guess < $num){ print "The number you guess is too small. Please enter another number:\n";}
        elsif ($guess > $num) {print "The number you guess is too high. Please enter another number:\n"}
        else{
            print "Bingo!\n";
            last;
        }
    }
}
