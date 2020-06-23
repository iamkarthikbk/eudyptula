#!/bin/bash
sudo insmod task09.ko
ls -al /sys/kernel/eudyptula/
sudo cat /sys/kernel/eudyptula/id
sudo echo "Some Random Text" > /sys/kernel/eudyptula/id
echo $?
sudo echo "a24a6bdd6a14" > /sys/kernel/eudyptula/id
echo $?
sudo cat /sys/kernel/eudyptula/jiffies
sudo cat /sys/kernel/eudyptula/jiffies
su -c "echo 'WARNING: Extremely long text::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::END' > /sys/kernel/eudyptula/foo"
sudo cat /sys/kernel/eudyptula/foo
sudo dd if=/dev/urandom of=/sys/kernel/eudyptula/foo bs=3 count=5000
echo $?
sudo rmmod task09.ko
