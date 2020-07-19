#!/bin/bash
sudo insmod task18.ko
ls -al /dev/eudyptula
file /dev/eudyptula
ps -ef | grep eudyptula
echo -n "Alice" > /dev/eudyptula
echo -n "Bob" > /dev/eudyptula
sleep 15
echo -n "Dave" > /dev/eudyptula
echo -n "Gena" > /dev/eudyptula
sudo rmmod task18.ko
ls -al /dev/eudyptula
ps -ef | grep eudyptula
