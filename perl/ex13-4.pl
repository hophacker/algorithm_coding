#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex13-4.pl
#
#        USAGE: ./ex13-4.pl  
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
#      CREATED: 01/15/2014 02:22:21 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";


#unlink @ARGV;

foreach (@ARGV){
    unlink $_ or warn "Can't unlink $_, continuing\n";
}
