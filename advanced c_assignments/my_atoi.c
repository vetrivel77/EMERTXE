/*
name: vetrivel.p
date: 21/07/2022
description: A36 - WAP to implement atoi function 
sample i/p and o/p:
Test Case 1 :
Enter a numeric string: 12345
String to integer is 12345

Test Case 2 :
Enter a numeric string: -12345
String to integer is -12345

Test Case 3 :
Enter a numeric string: +12345
String to integer is 12345

Test Case 4 :
Enter a numeric string: +-12345
String to integer is 0

Test Case 5 :
Enter a numeric string: 12345-
String to integer is 12345

Test Case 6 :
Enter a numeric string: abcd12345
String to integer is 0

Test Case 7 :
Enter a numeric string: 12345abcd
String to integer is 12345

*/

#include <stdio.h>
#include <string.h>

int my_atoi(const char str[]);
int main()
{   
    // string declration 
    char str[20];
    
    // read string from user
    printf("Enter a numeric string : ");
    scanf("%s", str);
    
    // display the results
    printf("String to integer is %d\n", my_atoi(str));

    return 0;
}

int my_atoi(const char*str)

{   
    // varible declaration  
    int sign = 1, base = 0, i = 0,num=0;
    
    // to skip the space charcter
    while (str[i] == ' ')    
    {
        i++;   
    }
    
    // intialize sign value to find str +ve or -ve
    if (str[i] == '+' || str[i] == '-')
    {    
        if(str[i] == '-')
        {
            sign= -1;
        }       
        i++;   
    }
    
    // run loop to end of the string
    // to check non zero numeric
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {       
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return sign * num;

}

