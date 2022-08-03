<<doc
name: vetrivel.p
date: 17/05/2022
description: Read 'n' and generate a pattern given below (number increation from top to bottom)
sample i/p: Enter the number:4
sample o/p: 1
            2 3 
            4 5 6
            7 8 9 10

doc

#!bin/bash
read -p "enter the number:" n   #read the number from the user

i=1                             #initilization value 1 2 3 4...
for row in `seq $n`             #loop for number of row
    do 
        for col in `seq $row`   #loop for number of colomns
        do
          echo -n "$i "         #to print the i valuve
          i=$((i + 1))          # i=i+1 that valuve i variable to print the rows 

    done
  echo                          #to get the new line
done
