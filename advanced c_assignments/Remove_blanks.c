/*
Name: vetrivel.p
Date: 20/07/2022
Description: WAP to replace each string of one or more blanks by a single blank..
Sample i/p and o/p:

Test Case 1:
user@emertxe] ./remove_multi_space
Enter the string with more spaces in between two words
Pointers     are               sharp     knives.
Pointers are sharp knives.
Test Case 2:
user@emertxe] ./remove_multi_space
Enter the string with more spaces in between two words
Welcome                to Emertxe
Welcome to Emertxe
Test Case 1:
user@emertxe] ./remove_multi_space
Enter the string with more spaces in between two words
Welcome to Emertxe
Welcome to Emertxe
*/

#include <stdio.h>

// function prototype
void replace_blank(char []);  
int main()
{
	// string declaration
    char str[100];  
	// read string from user
    printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);			 
	
    // function call
    replace_blank(str);                 
    printf("%s\n", str);				    
}

void replace_blank(char *str)                                                               // function definition          	

{
	int i=0,j;                                                                              //control var declaration to point the addresses of the string... 

	while(str[i+1]!='\0')                                                                   //Until the next character is equal to \0 keep on iterating...
	{
		if(str[i]=='\t')
		{
			str[i]=' ';		         	                                                    //if there is ever a TAB found then replace it with ' '...
		}		
		if((str[i]==' ') && (str[i+1]==' ') || (str[i] == ' ') && (str[i+1]== '\t'))        //certain position we encounter ' ' and even next element is ' '
		{
			j=i;                                                                            //i is used for traversing string so we use another variable j

			while(str[j]!='\0')	                                                            //now j will start performing the replacement  till the end
			{
				str[j]=str[j+1];
				j++;   
			}
			i--;                                                                           //Because after all replacement done again going back to the address from where the replacement started...
		}
		i++;                                                                               //Then normally moving to the next character...
	}
}
