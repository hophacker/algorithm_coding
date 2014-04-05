#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex16-3.pl
#
#        USAGE: ./ex16-3.pl  
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
#      CREATED: 01/16/2014 10:36:19 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature qw/state say switch/;

if (`date` =~ /^(Sat|Sun)/){
    say "go play!";
}else{
    say "get to work";
}
