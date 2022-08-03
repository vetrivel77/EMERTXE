/*
name: vetrivel.p
date: 01/07/2022
description: A24 - WAP to implement your own islower() function
sample i/p and o/p:
Sample execution: -
Test Case 1:
user@emertxe] ./c_type_lib
Enter the character: a
Entered character is lower case alphabet
Test Case 2:
Enter the character:3
Entered character is not lower case alphabet
*/

#include <stdio.h>

int my_islower(int);                                                  // function name and parameters

int main()
{
    char ch;                                                          // variable declaration
    int ret;                                                          
    
    printf("Enter the character:");                                   // read char from user                                  
    scanf("%c", &ch);
    
    ret = my_islower(ch);                                             // function call                                            
    
    if(ret)                                                           // return value stored in ret based on ret value to print the message

        printf("Entered character is lower case alphabet\n");
    else
        printf("Entered character is not lower case alphabet\n");

    return 0;
}

int my_islower(int ch)                                                // function prototype
{
    if ( ch >= 97 && ch <= 122 )                                      // ascii value of lower case letter range
    {
        return 1;
    else
        return 0;
    }
}
