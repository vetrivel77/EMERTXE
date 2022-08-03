<<doc
name:vetrivel.p
date: 26/05/2022
desciption: Use pipes or redirection to create an infinite feedback loop.
sample i/p and o/p:
1. ./redirection.sh
Before loop file contents
Hai hello
After loop file contents
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
.
.
.

doc

#!/bin/bash

echo "Before loop file contents"                               # before looping file contents

cat output.txt                                                 # using cat to shown the file contents

echo "After loop file contents"                                # after file loop contents infinte running

echo `tail -f output.txt >> output.txt | tail -f output.txt`   # using tail and follow up file to redirection file
                                                               # using piping tail follow up using contineusaly running file content
                                                               # using ctrl+c to stop the infinite file contents
                                                               



