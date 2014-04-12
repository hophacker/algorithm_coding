#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex14-3.pl
#
#        USAGE: ./ex14-3.pl  
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
#      CREATED: 01/15/2014 05:29:40 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";
use feature "say";

my $str = shift @ARGV; chomp($str);
my $sub = shift @ARGV; chomp($sub);

for (my $pos=-1;;){
    $pos = index $str, $sub, $pos+1;
    last if $pos == -1;
    say $pos . " ";
}
