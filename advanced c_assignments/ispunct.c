/*
name: vetrivel.p
date: 02/07/2022
description: A25 - WAP to implement your own ispunct() function
sample i/p and o/p:
Sample execution:
Test Case 1:
user@emertxe] ./c_type_lib
Enter the character: a
Entered character is not punctuation character
Test Case 2:
Enter the character:$
Entered character is punctuation character
*/

#include <stdio.h>

int my_ispunct(char ch);                                                    // function and parameters

int main()
{
    char ch;                                                               // varaible declaration
    int ret;
    
    printf("Enter the character:");                                        // read char from user
    scanf("%c", &ch);
    
    ret = my_ispunct(ch);                                                  // function call

    if(ret)                                                                // return character value stored in ret
        
        printf("Entered character is punctuation character\n");            // value within the range character to print the message
    
    else
       
        printf("Entered character is not punctuation character\n");        // not within range character to print the error message

    return 0;
}

int my_ispunct(char ch)                                                    // function prototype

{

    if((ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 126))     // ascii value of  punctuation character range within the range return the value to ret                                      
    
        return 1;        
    else        
        return 0;
       
}

