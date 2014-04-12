#!/usr/bin/env perl 
## Copyright (C) 2014 by Jie Feng Truly
#===============================================================================
#
#         FILE: ex9-5.pl
#
#        USAGE: ./ex9-5.pl  
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
#      CREATED: 01/12/2014 02:02:14 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";

my %do_these;
foreach (@ARGV){
    $do_these{$_} = 1;
}
while (<>){
    if (/^## Copyright/){
        delete $do_these{$ARGV};
    }
}

@ARGV = sort keys %do_these;
print "@ARGV";
$^I="";
while(<>){
    if (m/^#!/){
        $_ .= "## Copyright (C) 2014 by Jie Feng Truly\n";
    }
    print;
}
