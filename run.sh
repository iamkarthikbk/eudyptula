#!/bin/bash
sudo umount /sys/kernel/debug/
sudo mount -t debugfs none /sys/kernel/debug/ -o users
make
sudo insmod task08.ko
ls -al /sys/kernel/debug/eudyptula
cat /sys/kernel/debug/eudyptula/id
cat /sys/kernel/debug/eudyptula/jiffies
cat /sys/kernel/debug/eudyptula/jiffies
echo "Random text" > /sys/kernel/debug/eudyptula/id
echo $?
echo "a24a6bdd6a14" > /sys/kernel/debug/eudyptula/id
echo $?
su -c "echo 'I am root :)' > /sys/kernel/debug/eudyptula/foo"
cat /sys/kernel/debug/eudyptula/foo
sudo rmmod task08.ko
