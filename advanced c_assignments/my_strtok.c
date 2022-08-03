/*
name: vetrivel.p
date: 24/02/2022
description: A40 - WAP to implement strtok function
sample i/pa nd o/p:
Test Case 1:
user@emertxe] ./my_strtok
Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi
Mumbai

Test Case 2:
user@emertxe] ./my_strtok
Enter string1 : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[]);

int main()
{
    // char array declaration
    char str[50], delim[50];
    // read string freom user
    printf("Enter the string  : ");
    scanf("%s", str);
    
    __fpurge(stdout);
    // read delimeter from user
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    
    __fpurge(stdout);
    
    // function call
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }
}
// function definition
char *my_strtok(char str[], const char delim[])

{
	int j = 0;                                   // To iterate delim string till '\0'
	static int i;                                //To iterate main string till '\0'..Static var bcoz to continue with next character after replacing \0 char when token found in string
	static char *temp;                           //To take the base addr of main string initially and keep moving with next characters
	int length = i;                              //This var actually confirms whether both prev and present char are \0, if yes then without returning any addr, moving with next char in string
	if ( str != NULL )                           //If str is not equal to NULL addr then temp takes addr of str, for first time when fn called
	{
		temp = str;
	}
	while ( temp[i] != '\0')                     //Iterating with all characters from main string and checking for tokens
	{
		j = 0;
		while ( delim[j] != '\0' )               //Iterating all tokens with each char of main string and if found equal then replacing it
		{
			if ( delim[j] == temp[i] )           //If token found in string
			{
				temp[i] = '\0';                  //Making that char in string as \0
				i++;                             //Then moving with next char
				if (temp[length] != '\0')        //If the prev char was not \0, then returning the base addr for first and then addr after \0
				{
					return (&temp[length]);
				}
				else
				{
					length = i;                  //If prev char and present char became \0, then just moving with next char
					i--;                         //To compensate i++ present after inner while loop
					break;                       //breaks from inner while loop
				}
			}
			j++;
		}
		i++;
	}
	if ( temp[length] == '\0' )                  //If \0 has been reached in main string then returning NULL as per behaviour of strtok
	{		
		return NULL;
	}
	else
	{
		return (&temp[length]);                  //returning the addr...
	}
}
