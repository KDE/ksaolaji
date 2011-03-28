#! /bin/bash 
$EXTRACTRC *.rc *.ui *.kcfg >> rc.cpp
$XGETTEXT *.cpp cleaners/*.cpp -o $podir/ksaolaji.pot
rm -f rc.cpp
