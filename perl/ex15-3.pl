#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex15-3.pl
#
#        USAGE: ./ex15-3.pl  
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
#      CREATED: 01/16/2014 03:23:18 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature qw/state say switch/;





foreach (@ARGV){
    default {print $_ . ":";continue}
    when (-w $_) {print "writable " ;continue} 
    when (-r $_) {print "readable " ;continue}
    when (-x $_) {print "excutable " ;continue}
    say "";
}
