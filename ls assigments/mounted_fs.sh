<<doc
name: vetrivel.p
date: 24/05/2022
description: Write a script to determine whether a given file system or mount point is mounted
sample i/p and o/p: 

1. ./mounted_fs.sh /dev/sda2
File-system /dev/sda2 is mounted on / and it is having 98%
used space with 3298220 KB free.
2. ./mounted_fs.sh /dev
/dev is not mounted.
3. ./mounted_fs.sh
Error : Please pass the name of the file-system through command line.

doc

#!/bin/bash


file=(`df | cut -d" " -f1`)                                              # file systems names store
moun=(`df | tr -s ' ' |cut -d" " -f6`)                                   # to check mounted on 
use=(`df | tr -s ' ' |cut -d" " -f5`)                                    # to check mounted percentage 
f=(` df | tr -s ' ' |cut -d" " -f4`)                                     # avalilable free space
count=0                                                                  # count valuve assume 0
l=$((${#file[@]}-1))                                                     # lenghth of array

if [ $# -gt 0 ]                                                          # to check cla passed or not

then
    for i in `seq 1 $1`                                                  # using for loop in seq 1 and $1
     
    do
      if [ $1 = ${file[$i]} ]                                            # $1 equal to file system to i valuve
       then
         echo " File-system $1 is mounted on / and it is having $use used space with $f free " # mounted on and use and free avalible space all are shown in the output
             
            count=$(($count+1))                                          # to count value plus to 1
            
             exit                                                         

        fi
    done
    if [ $count -eq 0 ]                                                  # only file system name  only shown the details
    then
        echo " $1 is not mounted."                                       # not mounted file shown
    fi
else    
    echo " Error : Please pass the name of the file-system through command line." # cla not passing to print the error
fi

