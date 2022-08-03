<<doc
name: vetrivel.p
date: 22/05/2022
description:Given album name and corresponding directory, this scripts renames the jpg files with new name passed through command line
sample i/p:1) ./rename_album.sh day_out
           2) ./rename_album.sh
sample o/p:
1) 
All .jpg files in current directory is renamed as
day_out001.jpg day_out002.jpg day_out003.jpg day_out005.jpg day_out004.jpg
2) 
Error : Please pass the prefix name through command line.


doc


#!/bin/bash

if [ $# -gt 0 ]                                                # checking cla file content or not

then
    
    arr=(`ls *.jpg`)                                           # using array store all elements

for i in ${arr[@]}                                             # 0,1,2,3,4,5..

   do

       a=`echo $i | tr -cd '[:digit:]'`                        # using tr method to reduce the digit
        
       mv $i $1$a.jpg                                          # using mv command $i to $1
done

else

     echo "please pass the prefix name through command line"  # no content in cla to prin the error
 fi
