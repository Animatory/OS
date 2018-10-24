#!/bin/bash
chmod 666 _ex3.txt > ex3.txt
ls -l _ex3.txt > ex3.txt
chmod 767 _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 777 _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "660 for ex3.txt means read and write for owner and group and none permissions for others" >> ex3.txt
echo "775 for ex3.txt means all permissions for owner and group and read and execute for others" >> ex3.txt
echo "777 for ex3.txt means all permissions for all" >> ex3.txt

