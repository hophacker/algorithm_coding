#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex12-3.pl
#
#        USAGE: ./ex12-3.pl  
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
#      CREATED: 01/14/2014 10:35:40 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";
use feature say;

die "No files supplied!\n" unless @ARGV;
foreach (@ARGV){
    say "$_ is readable, writable and owned by use.\n" if -o -r -w $_;
}
