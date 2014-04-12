#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex13-8.pl
#
#        USAGE: ./ex13-8.pl  
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
#      CREATED: 01/15/2014 03:18:08 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";
use feature "say";

opendir DH, ".";

foreach (readdir DH){
    my $dest = readlink $_;
    print "$_ -> $dest\n" if defined $dest;
}
