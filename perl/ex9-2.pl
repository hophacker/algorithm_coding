#!/usr/bin/env perl 
## Copyright (C) 2014 by Jie Feng Truly
#===============================================================================
#
#         FILE: ex9-2.pl
#
#        USAGE: ./ex9-2.pl  
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
#      CREATED: 01/12/2014 12:30:01 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";

my $in = $ARGV[0];
unless (defined $in){
    die "Usage: $0 filename";
}

my $out = $in;
$out =~ s/(\.\w+)?$/.out/;

unless (open IN, "<$in"){
    die "Can't open '$in':$!";
}
unless (open OUT, ">$out"){
    die "Can't write '$out': $!";
}
while(<IN>){
    s/[Ff]red/\ULarry/g;
    print OUT $_;
}
