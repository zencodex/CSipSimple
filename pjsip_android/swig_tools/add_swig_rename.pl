#!/usr/bin/perl
$/ = undef;
$_ = <>;

s/PJ_DECL.*\s+((pjsua_([A-Za-z1-9_\-]+))\s*\([^)]+\));/%rename($3) $2;\n%javamethodmodifiers $1 "public synchronized";\n$&/g;
print;
