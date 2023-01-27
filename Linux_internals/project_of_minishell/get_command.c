#include "main.h"

//extract the command untill space or new line is encoundered
char *get_command(char *input_string)
{    
    //varible declartion
    static char command[25] = {'\0'};
    int i = 0;

    while(1)
    {
        if(*input_string == ' ' || *input_string == '\0')
        {
            break;
        }
        command[i++] = *input_string;
        input_string++;
    }
    command[i] = '\0';
    return command;
}

