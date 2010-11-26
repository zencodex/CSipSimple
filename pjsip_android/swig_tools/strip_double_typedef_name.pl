#!/usr/bin/perl
$/ = undef;
$_ = <>;

s/typedef[^{;]*((struct|enum)[^{;]*\{([^{}]*|(\{[^{}]*\})*)*\})([^;]*);/$1;/msg;
print;
