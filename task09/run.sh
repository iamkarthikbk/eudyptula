#!/bin/bash
sudo insmod task09.ko
ls -al /sys/kernel/eudyptula/
cat /sys/kernel/eudyptula/id
echo "some random text" > /sys/kernel/eudyptula/id
echo $?
echo "a24a6bdd6a14" > /sys/kernel/eudyptula/id
echo $?
sudo cat /sys/kernel/eudyptula/jiffies
sudo cat /sys/kernel/eudyptula/jiffies
su -c "echo 'WARNING: EXTREMELY LONG TEXT:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LONG TEXT ENDED' > /sys/kernel/eudyptula/foo"
cat /sys/kernel/eudyptula/foo
sudo bs=3 if=/dev/urandom of=/sys/kernel/eudyptula/foo
sudo rmmod task09.ko
