
#!/bin/bash

hour=$(date +"%H")

d=$(date +"%A %d in %B of %Y (%r)")

if [ $hour -ge 5 -a $hour -lt 12 ]
then
    
h="good morning have a nice day!, $USER"

elif [ $hour -ge 12 -a $hour -lt 13 ]

then 
  h="good noon, $USER"
  
  elif [ $hour -ge 14 -a $hour -lt 17 ]
  then
     h="good afternoon, $USER"

 elif [ $hour -ge 17 -a $hour -lt 21 ]
 then
    
     h="good evening, $USER"
 
else
     h="gud night end of the day,$USER"
 fi
 echo "$h"
echo "This is $d"   























