/*
Name: vetrivel.p
Date: 05/08/2022
Description:-Generate consecutive NRPS of length n using k distinct character
Sample i/pa nd o/p:
Test Case 1:
user@emertxe] ./nrps
Input:-
Enter the number characters C : 3
Enter the Length of the string N : 6
Enter 3 distinct characters : a b c
Output:-
Possible NRPS is abcbca

Test Case 2:
Input:-
Enter the number characters C : 3
Enter the Length of the string N : 7
Enter 3 distinct characters : a b a
Output:-
Error : Enter distinct characters
*/

#include <stdio.h>

// function prototype
void NPRSString(char str[] , int len, int c);

int main()
{
    // varible and string declaration
    int n, c, i, j;       
    char distinct[100];
   
    // read number from user
    printf("Enter the number characters C :");
    scanf("%d", &c);

    // read length from user 
    printf("Enter the Length of the string N : ");
    scanf("%d", &n);
    
    // dintinct number
    printf("Enter 3 distinct characters : ");
    for (i = 0; i < c; i++)
    {
          scanf("\n%c", &distinct[i]);  
    }    
    // if unique chaaracters calling nrps function
    for (i = 0; i < c; i++)         
    {
        for (j = (i+1); j < c; j++)
        {
            if(distinct[j] == distinct[i] )
            {
                printf("Error : Enter distinct characters\n");
                return 1;
            }
        }
    }
    printf("Possible NRPS is\n");
    
    NPRSString(distinct, n, c);
          
    return 0;
}
// function definition
void NPRSString(char str[] , int len, int c)     

{
    // varible declaration
    int i, val = 0, count = 0; 

    // printing n characters
    for (i = 0; i < len; i++)      
    {
        if(i%c == 0 && i != 0)
		{
			val++;
		}
        // printing reverce order
        printf("%c", *(str+((i+val)%c)));
    }
    
}
