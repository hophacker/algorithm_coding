#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex16-2.pl
#
#        USAGE: ./ex16-2.pl  
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
#      CREATED: 01/16/2014 10:31:43 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature qw/state say switch/;

open STDOUT, ">ls.out" or die "Can't write to ls.out: $!";
open STDERR, ">ls.err" or die "Can't write to ls.out: $!";

chdir "/" or die "Can't chdir to root directory: $!";
exec "ls", "-l" or die "Can't exec ls: $!";
