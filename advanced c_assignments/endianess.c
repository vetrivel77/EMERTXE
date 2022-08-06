/*
name: vetrivel.p
description: WAP to convert Little Endian data to Big Endian
sample i/p and o/p:
Sample execution: -
Test Case 1:
user@emertxe] ./endianness
Enter the size: 2
Enter any number in Hexadecimal: ABCD
After conversion CDAB
Test Case 2:
Enter the size: 4
Enter any number in Hexadecimal: 12345678
After conversion 78563412
*/

#include <stdio.h>
int main()
{
    // varible declaration
	int size, num; 

    // read size from user
	printf("Enter the size: ");
	scanf("%d", &size);

    // read hexadecimal value from user
	printf("Enter any number in Hexadecimal: ");
	scanf("%X", &num); 
    // ptr varible stroing addr of varible number
	char *ptr = (char *)&num; 

    // temporary varible
	char temp; 
    // short varible
	if ( size == 2 ) 
	{
		temp = *ptr;
		*ptr = *(ptr+1);
		*(ptr+1) = temp;
	}
    // swaping the values
	else if ( size == 4 ) 
	{
		char temp1;
		temp = *ptr;
		*ptr = *(ptr+3);
		*(ptr+3) = temp;        
		temp1 = *(ptr+1);
		*(ptr+1) = *(ptr+2);
		*(ptr+2) = temp1;
	}
	printf("After conversion %X\n", num); 
	return 0;
}
