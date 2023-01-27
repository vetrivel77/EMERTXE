#include "main.h"

void execute_internal_command(char *input_string)
{
    //exit-->terminate the program
    if(strncmp("exit",input_string,4) == 0)
    {
        exit(2);
    }
    //pwd->print the current location
    if(strncmp("pwd",input_string,3) == 0)
    {
        system("pwd");
    }
    //cd-->change the directory
    //input_string -> cd abc
    if(strncmp("cd",input_string,2) == 0) 
    {
        //implement cd command with mulitiple spaces
        //varible declartion
        int i,count=0;
        for(i = 2 ; input_string[i] == ' ' ; i++)
        {
            count++;
        }
        chdir(&input_string[2+count]);
    }    
}
