#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex13-3.pl
#
#        USAGE: ./ex13-3.pl  
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
#      CREATED: 01/15/2014 01:48:53 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";


while(1){
    chomp( $dir =  <STDIN> );
    if ($dir =~ /quit/i){
        last;
    }elsif ($dir =~ /^\s*$/){
        chdir or die "cannot chdir to $dir: $!";
    }else{
        chdir $dir or die "cannot chdir to $dir: $!";
    }
    opendir DH, "." or die "cannot opendir dot: $!";
    foreach (sort readdir DH){
        print "$_\n";
    }
}
