#!/bin/sh
g++ -o povgen main.cpp
./povgen
povray disco.ini
ffmpeg -f image2 -i disco%03d.png -vcodec mpeg4 -b 10000k disco.avi
mplayer disco.avi -loop 5
