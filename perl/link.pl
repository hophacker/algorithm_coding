#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: link.pl
#
#        USAGE: ./link.pl  
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
#      CREATED: 01/15/2014 02:57:59 AM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";
use File::Basename qw/ basename dirname /;
use File::Spec;


my $link = 0;
while(my $par = shift @ARGV){
    if ($par =~ /-s/){
        $link = 1;
    }elsif(!$original){
        $original = $par;
    }elsif(!$new){
        $new = $par;
    }else{
        die "You have provided too many arguments!\n";
    }
}

if (!-e $original){
    die "The original file does not exists!\n";
}elsif (-e -f $new){
    die "The target symbol alreay exists!\n";
}elsif (-d $new){
    my $basename = basename($original);
    $dest = File::Spec->catfile($new, $basename);
    if ($link){
        symlink $original, $dest or die "Can't make symbolic link: $!";
    } else {
        link $original, $dest or die "Can't make hard link: $!";
    }
}else{
    $baseDir = &dirname($new);
    if (!-e $baseDir){
        die "The dir of destination does not exists!\n";
    }else{
        if ($link){
            symlink $original, $new or die "Can't make symbolic link: $!";
        }else{
            link $original, $new or die "Can't make hard link: $!";
        }
    }
}
