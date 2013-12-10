BEGIN {print "Hi!"; x = 1;}
END {print "Bye!";}
x==1 {print "1"; x = 3;}
x==2 {print "2"; x = 4;}
x==3 {print "3"; x = 2;}
x==4 {print "4";}
/.2./ {
    s = 0; 
    for(i = 3; i < 8; i++) {
        s += $i;
    }
    print $2" - "(s)/5;}
