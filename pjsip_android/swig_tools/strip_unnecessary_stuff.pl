#!/usr/bin/perl
$/ = undef;
$_ = <>;

# Everything before PJ_BEGIN_DECL
s/.*PJ_BEGIN_DECL//msg;
# Everything after PG_END_DECL
s/PJ_END_DECL.*//msg;
print;
