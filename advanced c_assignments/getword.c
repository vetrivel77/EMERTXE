/*
name: vetrivel.p
date: 20/07/2022
description: WAP to implement getword function
sample i/p and o/o:
Sample execution: -
Test Case 1:
user@emertxe] ./getword
Enter the string : Welcome to Emertxe
You entered Welcome and the length is 7

Test Case 2:
user@emertxe] ./getword
Enter the string : Hello
You entered Hello and the length is 5
*/

#include <stdio.h>

int getword(char str[]);

int main()
{        
    // varaible declaration        
    int len = 0;	    
    char str[100];        
        
    // read string from user		
    printf("Enter the string : ");		
    scanf(" %[^\n]", str);
		
    len = getword(str);
                
    // display the results       
    printf("You entered %s and the length is %d\n", str, len);
}

int getword(char *str) 

{
	
    int length = 0;
	while ( *str != ' ' && *str != '\0') //condition to stop incrementing the length count if it is null char or space char...
	{
		*str++;
        length++;
	}
	if (*str == ' ') //while printing the string in the main fn i have to just print the first string, so this statement...
		*str = '\0';
	return length;
}
