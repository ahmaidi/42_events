#!/usr/bin/perl
use strict;
use warnings;

print "Enter a string: "; 
my $str = <STDIN>;
chomp $str;

if ( $str eq reverse($str) ) {
     print "PALINDROME!\n";
}
else {
     print "NOT A PALINDROME! \n";
}