<<doc
name: vetrivel.p
date: 28/05/2022
description: For each directory in the $PATH, display the number of executable files in that directory
sample i/p and o/p:
1. ./executable_path.sh
Current dir: /usr/local/sbin
current count: 0
Current dir: /usr/local/bin
current count: 0
Current dir: /usr/sbin
current count: 205
Current dir: /usr/bin
current count: 1889
Current dir: /sbin
current count: 187
Current dir: /bin
current count: 159
Current dir: /usr/games
current count: 5
Current dir: /usr/local/games
current count: 0
Total – 2445

doc

#!/bin/bash

arr=(`echo $PATH | tr ":" " "`)         # cut the path form user store in arr

total=0                                                

for i in `seq 0 $((${#arr[$i]}-1))`     # using i for loop in full elements
do
    count=0

if [ -e  ${arr[$i]} ]                   #  to execution full elemnets

then

    cd ${arr[$i]}                       # change the directory using cd
    
    dir=(`ls`)                          # using  store all in the the one array
   
echo "current dir: ${arr[$i]}"          # to print the dir name

for j in `seq 0 $((${#dir[@]}-1))`      # using   j for loop in full elements
do
 if [ -x ${dir[$j]} -a -f ${dir[$j]} ]  
    then

        count=$(($count+1))            # to count the i valuve
    fi

done  
   echo "current count:$count"         # to print the count valuve
    
total=$(($total+$count))               # count plus total valuve
      
   fi
  done
       
  echo "total-$total"                 # to print the total elements    
     
