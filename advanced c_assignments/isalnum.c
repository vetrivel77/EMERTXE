/*
name: vetrivel.p
date: 02/07/2022
description: A22 - WAP to implement your own isalnum() function
sample i/p and o/p:
Sample execution: -
Test Case 1:
user@emertxe] ./c_type_lib
Enter the character: a
The character 'a' is an alnum character.
Test Case 2:
Enter the character: ?
The character '?' is not an alnum character.
*/

#include <stdio.h>

int my_isalnum(char ch);                                                   // function name and parameters

int main()
{
    char ch;                                                               // variable declaration
    int ret;
    
    printf("Enter the character:");                                        // read char value from user
    scanf("%c", &ch);
    
    ret = my_isalnum(ch);                                                  // function call
     
    if(ret)                                                                // return character value stored in ret 
        
        printf("Entered character is alphanumeric character ");            // within the range char value to print the message
    
    else
        
        printf("Entered character is not alphanumeric character");         // not within range the char value to print the error message    
        
    return 1;
}    
    
int my_isalnum(char ch)                                                    // function prototype

{            
    if((ch >= 48 && ch <= 57) || (ch <= 64 && ch >=90) || ( ch >= 97 && ch <= 122))  // ascii value of lower case character value ranges char value to  return the value to ret

        return 1;        
    else        
        return 0; 

}
