#!/bin/bash

echo "Start Building";
export LD_LIBRARY_PATH=libs
unset LD_LIBRARY_PATH
g++ -fPIC -m32 -L libs -lsubhook -lmempatch -std=c++11 -shared -o gain_money.so main.cpp
echo "Build Done";
mv gain_money.so /home/gamed/gain_money.so
echo "File Moved";
cd /home/gamed
export LD_DEBUG=libs
LD_PRELOAD=./gain_money.so ./gs gs01
echo "Done";
