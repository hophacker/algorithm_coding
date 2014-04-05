#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex13-5.pl
#
#        USAGE: ./ex13-5.pl  
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
#      CREATED: 01/15/2014 02:25:23 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use File::Basename qw/ basename dirname /;
use File::Spec;
use feature "state";

my ($original, $new) = @ARGV;


if (!-e $original){
    die "The original file does not exists!\n";
}elsif (-e -f $new){
    die "The destination alreay exists!\n";
}elsif (-d $new){
    my $basename = basename($original);
    $dest = File::Spec->catfile($new, $basename);
    rename $original, $dest;
}else{
    $baseDir = &dirname($new);
#    $baseName = &basename($new);

    if (!-e $baseDir){
        die "The dir of destination does not exists!\n";
    }else{
        rename $original, $new;
    }
}
