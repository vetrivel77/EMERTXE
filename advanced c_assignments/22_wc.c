/*
Name: vetrivel.p
Date: 13/07/2022
Description: WAP to count no of characters,words and lines, entered through stdin
Sample i/o and o/p:

Test case 1:
hello world
dennis ritchie
linux
character count: 33
word count: 5
line count: 3

Test case 2:
Hello    world
dennis  ritcchie
linux
characte count: 39
line count: 3
word count: 5
*/

#include<stdio.h>

int main()
{
    // varible declaration
    char option;
    int line_count = 0, word_count = 1, char_count = 0;

    // new line increment line and word count
    char ch, temp = 'a';
    while((ch = getchar()) != EOF)
    {
        if(ch == '\n') 
        {
            line_count++;
            word_count++;

            if(temp == ch) // if next character is newline decrement the word count
            {
                word_count--;
            }
            temp = ch;
        }
        else
        {
            if(ch == ' ' || ch == '\t')
            {
                word_count++;
                
                if(temp == ch)
                {
                    word_count--;
                }
            }
            temp = ch;
        }
        char_count++;
    }    
    // if EOF ctrl+d break the loop
    if(ch == EOF && temp == '\n')  
    {
        word_count--;
    }
    // display the results
    printf("character count = %d\n", char_count);
    printf("line_count = %d\n", line_count);
    printf("word_count = %d\n", word_count);

    return 0;
}
