{a[$1]++;}
END {for (t in a) print t "->" a[t];}
