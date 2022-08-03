/*
name: vetrivel.p
date: 22/07/2022
description: A39 - WAP to reverse the given string using recursive method
sample i/p and o/p:
Test Case 1:
user@emertxe] ./str_rev
Enter a string : Hello World
Reverse string is : dlroW olleH

Test Case 2:
user@emertxe] ./str_rev
Enter a string : EMERTXE
Reverse string is : EXTREME
*/

#include <stdio.h>
#include <string.h>

void reverse_recursive(char str[], int ind, int len);

int main()
{
    // string declaration
    char str[30];

    // read string fromn user   
    printf("Enter any string : ");
    scanf("%29[^\n]", str);
    
    //function call
    reverse_recursive(str,0,strlen(str)-1);
    
    // display the results
    printf("Reversed string is: %s\n", str);
}

void reverse_recursive(char *str, int ind, int len)

{
    // character declaration
    char ch;
    
    // to check ind greaterthan len
    if (ind >= len)
    {
        return;
    }
    // swap the characters
    ch = *(str + ind);
    *(str+ind) = *(str+len);
    *(str+len) = ch;
   
    reverse_recursive(str,++ind,--len);
}

