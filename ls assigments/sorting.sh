
<<doc
name: vetrivel.p
date: 30/05/2022
description:Write a script to sort a given number in ascending or descending order
sample i/p and o/p:
Test Case 1: 
./sorting.sh -a 5 4 6 2 3 8 9 7 1
Ascending order of array is 1 2 3 4 5 6 7 8 9
Test Case 2: 
./sorting.sh -d 5 4 6 2 3 8 9 7 1
Descending order of array is 9 8 6 5 4 3 2 1
Test Case 3:
./sorting.sh 5 4 6 2 3 8 9 7 1
Error : Please pass the choice.
Usage : ./sorting -a/-d 4 23 5 6 3
Test Case 4: 
./sorting.sh
Error : Please pass the argument through command line.
Usage : ./sorting -a/-d 4 23 5 6 3
Test Case 5:
./sorting.sh -d 5 4 6 2 -3 8 -9 7 1
Descending order of array is 8 7 6 5 4 2 1 -3 -9
doc

#!/bin/bash

if [ $# -ne 0 ]                           # check cla passed or not

then
    arr=($@)                              # store all elements in one array
     l=$((${#arr[@]}-2))
     n=$(($l+1))                          # index valuve

     case ${arr[@]:0:1 } in               # case all elements one by one
     
         -a) for i in `seq $n`            # bubble swapping
         do
             for j in `seq $l`            # to acces the each array
             do
             h=$(($j+1))                  # j valuve add to 1
                a=` echo ${arr[$j]}`      # store j element
                b=` echo ${arr[$h]}`      # next array
    if [ $a -gt $b ]                      # to compare j element
    then       
        temp=$a                           # for swapping element
        a=$b                              # 2nd element store in 1st
        b=$temp
        arr[$j]=$a                        # stored swapped valuve
          arr[$h]=$b
    fi
done

done    
 echo -n " Ascending order of array is "  # to print the ascending valuve
    echo "${arr[@]:1:$n}" ;;              # print array valuve
    
-d) for i in `seq $n`                     # bubble swapping
do
    for j in `seq 1 $l`                   # for loop 2nd element
    do
        h=$(($j+1))                       # to increment the valuve
        a=` echo ${arr[$j]}`
        b=` echo ${arr[$h]}`
        
        if [ $a -lt $b ]                  # a lesssthan b
        then
            temp=$a                       # 1st element stored
            a=$b                          # 2nd element stored
            b=$temp 
            arr[$j]=$a
              arr[$h]=$b                  # swapped element stored

        fi
    done
done
echo  -n " Descending order of array is " # to print the decending valuve
    
echo "${arr[@]:1:$n}" ;;                  # print the array valve

*) echo " Error : Please pass the choice.
          Usage : ./sorting -a/-d 4 23 5 6 3 "
                                          # crt -a -d valuve not passed to print the error    
    esac
   
else
    echo " Error : Please pass the argument through command line.
         Usage : ./sorting -a/-d 4 23 5 6 3 "
fi                                        # cla not passed to print the error

