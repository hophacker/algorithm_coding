#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: ex11-1.pl
#
#        USAGE: ./ex11-1.pl  
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
#      CREATED: 01/14/2014 05:52:18 PM
#     REVISION: ---
#===============================================================================

#use strict;
use warnings;
use utf8;
use feature "state";
use Module::CoreList;

my %modules = %{ $Module::CoreList::version{5.008} };

foreach my $key(keys %modules){
    printf "%50s => %s\n" , $key , $modules{$key};
}
