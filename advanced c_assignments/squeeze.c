/*
name: vetrivel.p
date: 28/07/2022
description: A41 - Squeeze the character in s1 that matches any character in the string s2
sample i/p and o/p:
Test Case 1:
user@emertxe] ./squeeze
Enter s1 : Dennis Ritchie
Enter s2 : Linux
After squeeze s1 : Des Rtche

Test Case 2:
user@emertxe] ./squeeze
Enter s1 : Welcome
Enter s2 : Emertxe
After squeeze s1 : Wlco
*/

#include <stdio.h>

// function name and parameters
int squeeze(char str1[], char str2[]);

int main()
{
    // string declaration
    char str1[50], str2[50];
    
    // read string1 from user
    printf("Enter string1:");
    fgets(str1, 50, stdin);
    
    // read string2 from user
    printf("Enter string2:");
    fgets(str2, 50, stdin);
    
    // function call
    squeeze(str1, str2);
    
    // display the results   
    printf("After squeeze s1 : %s\n", str1);

    return 0;    
}
// function definition
int squeeze(char str1[], char str2[])

{
    // varaible declaration
    int i,j,k;    
    
    for (j=0; str2[j] != '\0';j++)                 // whether to str2 check the char tili null character
    {
        for (i=k=0; str1[i] != '\0';i++)           // whether str2 check to null character and char stoter in k
        {
            if (str1[i] != str2[j])                // whether to check str1 and str2 same character

                str1[k++]=str1[i];                 // str1 post increment happen both string same char value reduced
        }
    str1[k] = '\0';                                // str1 remaining char value stored in str[k] 
    }
  
}
