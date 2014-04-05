#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex16-1.pl
#
#        USAGE: ./ex16-1.pl  
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
#      CREATED: 01/16/2014 10:27:09 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature qw/state say switch/;

chdir "/" or die "Can't chdir to root directory: $!";
exec "ls", "-l" or die "Can't exec ls: $!";
