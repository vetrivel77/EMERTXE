<<doc

name: vetrivel.p
date: 23/05/2022
description: WAS to print contents of a directory without ls commandVirtual programming lab
sample i/p:
1. ./output_ls.sh
2. ./ouput_ls.sh ~ ~/ECEP
3. ./ouput_ls.sh Test
sample o/p:
1. ./output_ls.sh
Assignments Classwork
2. ./ouput_ls.sh ~ ~/ECEP
/home/user:
Downloads Documents Desktop Music Pictures Public Videos
ECEP
/home/user/ECEP:
Linux_Systems Advnc_C Linux_Internals Data_Structures MC
3. ./ouput_ls.sh Test
output_ls.sh: Cannot access ‘Test’ : No such a file or directory.

doc

#!/bin/bash

if [$# -eq 0]                                                               # to check the file
then

    echo *                                                                  # to print the current dir contents
else
 for i in $@                                                                # using loop i and $@
 do
        echo ~ $i                                                           # to change directory

if [ -d $i ]                                                                # to check dir or not
then
    echo $i

   cd                                                                       # to change the cureent dir
  
  echo *                                                                    # print the current content file

else       
         
echo "output_ls.sh: Cannot access ‘Test’ : No such a file or directory."    # dir not to print the error
    
fi                                                                       

done
fi






