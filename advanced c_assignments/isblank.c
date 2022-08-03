/*
name: vetrivel.p
date: 04/07/2022
description:A23 - WAP to implement your own isblank() function
sample i/p and o/p:
Sample execution: -
Test Case 1:
user@emertxe] ./c_type_lib
Enter the character: a
The character 'a' is not a blank character.
Test Case 2:
Enter the character:    //Entered space
The character ' ' is a blank character.
*/

#include <stdio.h>

int my_isblank(char ch);                                       // function and parameters

int main()
{
    char ch;                                                   // variable declaration
    int ret;
    
    printf("Enter the character:");
    scanf("%c", &ch);
    
    ret = my_isblank(ch);                                      // function call

    if(ret)                                                    // return character value stored in ret

        printf("The character is a blank character.\n");       // within the range to pint the mesaage
    else
        printf("The character is not a blank character.\n");   // not within range to print the error message

    return 1;
}

int my_isblank(char ch)                                         // function prototype

{                    
    if(ch == 32 || ch == 9)                                     // ascii value space and tap         
        
        return 1;        
    else
        return 0;

}
