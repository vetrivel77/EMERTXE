/*
name: vetrivel.p
date: 28/07/2022
description: WAP to check given string is Pangram or not
Sample i/p and o/p:

Test Case 1:
Enter the string: The quick brown fox jumps over the lazy dog
The Entered String is a Pangram String

Test Case 2:
Enter the string: The quick brown fox jumps over the dog
The Entered String is not a Pangram String
*/


#include <stdio.h>

// function name and parameter
int pangram( char []);

int main()
{   
    // string declaration
	char str[100]; 
    int val;
    
    // read string from user	
    printf("Enter the string: ");
	fgets(str,100,stdin);
    
    // function call
    val = pangram(str);
    
    // based on return value diaplay the results
    if (val)
    {
		printf("The Entered String is a Pangram String\n");
    }
	else
    {
		printf("The Entered String is not a Pangram String\n");
    }
	return 0;
}
// function definition
int pangram(char * str) 

{
    // varible declaration
	int i = 0,count=0;
    // all alphabets characters stored in one array
    int arr[26] = {0};

    // loop run till '\0' character
    while (*str)
	{
        // whether to check all alphabets charcters present or not..
        // whether increase thr array count
		if ((*str - 'A' == 0) || (*str - 'a' == 0)) 
			arr[0] = 1;
		else if ((*str - 'B' == 0) || (*str - 'b' == 0))
			arr[1] = 1;
		else if ((*str - 'C' == 0) || (*str - 'c' == 0))
			arr[2] = 1;
		else if ((*str - 'D' == 0) || (*str - 'd' == 0))
			arr[3] = 1;
		else if ((*str - 'e' == 0) || (*str - 'E' == 0))
			arr[4] = 1;
		else if ((*str - 'F' == 0) || (*str - 'f' == 0))
			arr[5] = 1;
		else if ((*str - 'G' == 0) || (*str - 'g' == 0))
			arr[6] = 1;
		else if ((*str - 'h' == 0) || (*str - 'H' == 0))
			arr[7] = 1;
		else if ((*str - 'i' == 0) || (*str - 'I' == 0))
			arr[8] = 1;
		else if ((*str - 'j' == 0) || (*str - 'J' == 0))
			arr[9] = 1;
		else if ((*str - 'k' == 0) || (*str - 'K' == 0))
			arr[10] = 1;
		else if ((*str - 'l' == 0) || (*str - 'L' == 0))
			arr[11] = 1;
		else if ((*str - 'M' == 0) || (*str - 'm' == 0))
			arr[12] = 1;
		else if ((*str - 'n' == 0) || (*str - 'N' == 0))
			arr[13] = 1;
		else if ((*str - 'o' == 0) || (*str - 'O' == 0))
			arr[14] = 1;
		else if ((*str - 'p' == 0) || (*str - 'P'== 0))
			arr[15] = 1;
		else if ((*str - 'q' == 0) || (*str - 'Q' == 0))
			arr[16] = 1;
		else if ((*str - 'r' == 0) || (*str - 'R' == 0))
			arr[17] = 1;
		else if ((*str - 's' == 0) || (*str - 'S' == 0))
			arr[18] = 1;
		else if ((*str - 't' == 0) || (*str - 'T' == 0))
			arr[19] = 1;
		else if ((*str - 'u' == 0) || (*str - 'U' == 0))
			arr[20] = 1;
		else if ((*str - 'v' == 0) || (*str - 'V' == 0))
			arr[21] = 1;
		else if ((*str - 'w' == 0) || (*str - 'W' == 0))
			arr[22] = 1;
		else if ((*str - 'x' == 0) || (*str - 'X' == 0))
			arr[23] = 1;
		else if ((*str - 'y' == 0) || (*str - 'Y' == 0))
			arr[24] = 1;
		else if ((*str - 'z' == 0) || (*str - 'Z' == 0))
		   arr[25] = 1;
		str++;
	}
    // to increment the all array count
	while ( i < 26 ) 
	{
		if ( arr[i] == 1 )
			count++;
		i++;
	}
    // whether to check count array values all alphabets present aren't
	if ( count < 26 )
		return 0;
	else
		return 1;
}
