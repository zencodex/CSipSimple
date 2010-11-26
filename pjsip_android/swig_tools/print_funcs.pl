#!/usr/bin/perl
$/ = undef;
$_ = <>;

while(/(PJ_DECL[^;]*;)/g) {
	print "$1\n";
}
