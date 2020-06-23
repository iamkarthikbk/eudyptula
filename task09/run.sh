#!/bin/bash
make
sudo insmod task09.ko
ls -al /sys/kernel/eudyptula/
cat /sys/kernel/eudyptula/id
sudo echo "some random text" > /sys/kernel/eudyptula/id
echo $?
sudo echo "a24a6bdd6a14" > /sys/kernel/eudyptula/id
echo $?
sudo cat /sys/kernel/eudyptula/jiffies
sudo cat /sys/kernel/eudyptula/jiffies
su -c "echo 'WARNING: EXTREMELY LONG TEXT:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LONG TEXT ENDED' > /sys/kernel/eudyptula/foo"
sudo cat /sys/kernel/eudyptula/foo
sudo dd bs=3 if=/dev/urandom of=/sys/kernel/eudyptula/foo count=5000
sudo rmmod task09.ko
