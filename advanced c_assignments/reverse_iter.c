/*
name: vetrivel.p
date: 21/07/2022
description: A38 - WAP to reverse the given string using iterative method
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

void reverse_iterative(char str[]);

int main()
{
    // array declaration
    char str[30];    
    
    // string declartion   
    printf("Enter any string :");
    scanf("%29[^\n]", str);
    
    //function call
    reverse_iterative(str);
    
    // display the results 
    printf("Reversed string is:%s\n", str);
}

void reverse_iterative(char * str)

{
    // varaible and pointer declaration
    int len,i;
    char *begin_ptr;
    char *end_ptr,ch;
    
    // get string length
    len=strlen(str);
    
    // initializing str into begin,end
    begin_ptr=str;
    end_ptr=str;
    
    // move to the end_ptr to the last charcter
    for (i=0; i < len-1;i++)   
    {
        end_ptr++;      
    }    
    // swap the char begin to end
    for (i=0; i < len/2;i++)
    {         
        ch = *end_ptr;        
        *end_ptr= *begin_ptr;       
        *begin_ptr=ch;
        // update pointer position
        begin_ptr++;           
        end_ptr--;
    }
}
