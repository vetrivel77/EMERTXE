<<doc

name: vetrivel.p
date: 26/05/2022
description: Display the longest and shortest user-names on the systemVirtual programming lab
sample i/p and o/p:
./largest_username.sh
The Longest Name is: speech-dispatcher
The Shortest Name is:lp

doc

#!/bin/bash


array=(`cat /etc/passwd | cut -d ":" -f1`)        # store the user files in array

small=${#array[0]}                                # store length in small

large=${#array[0]}                                # store length in large

for i in `seq 1 $((${#array[@]}-1))`              # take user file in using array

do
    if [ $small -gt ${#array[$i]} ]               # to compare small value user length

    then    
        small=${#array[$i]}                       # small valuve into the array length
    
    fi
   if [ $large -lt ${#array[$i]} ]                # large compare valve user file length
 
    then

        large=${#array[$i]}                       # large valuve into the array length
    
    fi  

done

for i in ${array[@]}                              # initialaization file length of array
do

    if [ ${#i} -eq $small ]                       # user file in small 
then

    echo "The Shortest Name is:$i"                # print the small file name
fi

if [ ${#i} -eq $large ]                           # user file in large
then

    echo "The Longest Name is:$i"                 # to print the large name
fi
done

