#include "main.h"

pid_t pid;
void scan_input(char *prompt, char *input_string)
{   
    //varible declartion
    char *command = "\0";
    int command_type,status;

    while(1)
    {  
        //clear the memory
        memset(input_string,'\0',25);        
        printf(ANSI_COLOUR_BLUE"[%s]$"ANSI_COLOUR_GREEN,prompt);
        
        //clear the output buffer
        fflush(stdout);
        scanf("%[^\n]s",input_string);

        //clear the input buffer
        getchar();
        
        //customize the promptm eg : input_string -> PS1=msh
        if(!strncmp("PS1=",input_string,4))
        {
            //customize the prompt
            if(input_string[4] != ' ')
            {
                strcpy(prompt,&input_string[4]);

                //clear the input string
                memset(input_string,'\0',25);
                continue;
            }
            printf("Command not found\n");
        }
        //to get a command
        command = get_command(input_string);
        //printf("command is %s\n",command);
        command_type = check_command_type(command);
        printf("command type is %d\n",command_type);
        
        //external commands
        if(command_type == EXTERNAL)
        {            
            
            /* create a child process and execute the command 
             * parent should wait for the child to complete */                        

            pid = fork();

            if(pid > 0 )
            {
                //parent process
                wait(&status);
                if(WIFEXITED(status))
                {
                    printf("child process terminated %d\n",pid);
                }
            }
            else if(pid == 0)
            {
                int ret_status = system(input_string);
                if(ret_status == 0)
                {
                    exit(1);
                }
            }
            else
            {
                perror("Fork : Failed");
                exit(1);
            }
        }
        //Implement call the family of echo functions
        echo(input_string,status);

        //Implement internal commands
        execute_internal_command(input_string);
    }

}
