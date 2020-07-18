#!/bin/bash
uname -a
hostnamectl
sudo insmod ./task17.ko
ls -al /dev/eudyptula
file /dev/eudyptula
ps -ef | grep eudyptula
sudo echo "gibberish" > /dev/eudyptula
echo $?
sudo echo "a24a6bdd6a14" > /dev/eudyptula
echo $?
sudo rmmod ./task17.ko
ls -al /dev/eudyptula
ps -ef | grep eudyptula
