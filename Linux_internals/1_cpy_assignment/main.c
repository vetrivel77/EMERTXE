/*
NAME : VETRIVEL P
DATE : 28/12/2022
DESCRIPTION :A01 - Implement a cp(copy) command with –p option
SAMPLE I/P AND O/P:
Pre-requisites:

Knowledge about system calls, How to read and understand ‘man pages’.
Command line arguments, File operation system calls (open, read, write, close, fstat ..etc

Objective:
   To understand and implement using basic system calls

Requirements:

Copy source file to destination file which passed through cmd-line arguments. After copying both files  must have equal size, even it’s a zero sized file.  Eg:  ./my_copy source.txt dest.txt
If arguments are missing show the usage (help) info to use
Implement a my_copy() function where you have to pass two file descriptors. Int my_copy(int source_fd, int dest_fd);
 If –p option passed copy permissions as well to destination (refer ‘fstat’ man page).  Eg: - ./my_copy –p source.txt dest.txt.
If the destination file is not present then create a new one with given name. In case if it is present show a confirmation from user to overwrite. Eg: - ./my_copy source.txt destination.txt .File  “destination.txt” is already exists. Do you want to overwrite (Y/n)
If user type ‘Y/n’ or enter key overwrite the destination with new file. In n/N don’t overwrite and exit from program.
Program should able handle all possible error conditions.

Sample execution:

When no arguments are passed ./my_copy Insufficient arguments
Usage:- ./my_copy [option]
When destination file is not exists ./my_copy source.txt dest.txt . New dest.txt file is created and source.txt file will be copied to dest.txt file
 When destination file exists ./my_copy source.txt dest.txt File “dest.txt” is already exists. Do you want to overwrite (Y/n)
When –p option passed ./my_copy –p source.txt dest.txt Permissions also copied from source file to destination file
*/

#include "main.h" 

int main(int argc,char *argv[])
{
    
    int s_fd, d_fd, read_len;
	char choice;

	//for -p to copy the permission mode
	struct stat sb;

   if (argc < 3)
    {
        printf("Insufficient arguments\n");
		printf("Usage:- ./my_copy [option] <source file> <destination file> \n");
        printf("please pass valid command line arguments\n");
        return -1;
    }
	/* check for -p permissions */
	if (strcmp(argv[1], "-p") == 0 )
	{
		printf("Permissions also copied from source file to destination file.\n");
		/* To open source.txt to read */
		if ( (s_fd = open(argv[2], O_RDONLY)) == -1 )
		{
			perror("open");
			return -1;
		}

		//get the permission of this file
		//stat(argv[2], &sb);
		if (stat(argv[2], &sb) )
		{
			perror("stat");
			return -1;
		}

		/* To create/ open dest.txt to copy the data */
        //d_fd = open(argv[2],O_CREAT | O_EXCL | O_WRONLY);
		if ( (d_fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1 )
		{

			printf("File %s is already exists.\n Do you want to overwrite (y/n): ", argv[2]);
			scanf("%c", &choice);

			if(choice == 'n' || choice == 'N')
			{
				return 0;
			}
			else if (choice == 'y' || choice == 'Y')
			{
				//for overwriting
				if ( (d_fd = creat(argv[3], 0664)) == -1 )
				{
					perror("open");
					return -1;
				}
			}

		}
		//change the permisions
		if (chmod(argv[3], sb.st_mode & 0777))   		
        {
        	perror("chmod");
			return -1;    		
        }
	
    }
    else            
    {      
        // read the 1 arg file content                  
        s_fd = open(argv[1],O_RDONLY);
        
        if(s_fd == -1)
        {
            printf("error : Please pass the source file\n");       
            return -1;
        }
        // write the content to 1st arg file to 2nd arg file
        d_fd = open(argv[2],O_CREAT | O_EXCL | O_WRONLY);
    
        if(d_fd == -1)
        {
            printf("File %s is already exists.\nDo you want to overwrite (y/n): ", argv[2]);                    
            // read choice from user
            scanf("%c",&choice);          
            if(choice == 'y' || choice == 'y')
            {
                d_fd = open(argv[2], O_TRUNC | O_WRONLY);
            }
            else if(choice == 'n' || choice == 'N')
            {
                return -1;
            }
        }
    }     
    // function call                   
    copy_con(s_fd,d_fd);      			
    close(s_fd);			
    close(d_fd);            
    return 0;
}   
//copy the data from source file to destination   
int copy_con(int s_fd, int d_fd)   
{
	    
    int read_len = 0;	    
    char buff[BUFF_SIZE];
	   
    //read the data from the source.txt till end and copy	    
    while( ((read_len = read(s_fd, buff, BUFF_SIZE)) != -1 ) && (read_len != 0) )	    
    {		    
        if( write(d_fd, buff, read_len) == -1 )		    
        {			    
            close(s_fd);			    
            close(d_fd);			    
            return -1;		    
        }
	    
    }        
    // to check file content present are not        
    if(d_fd =! NULL)        
    {            
        printf("Success : file contents are copied\n");        
    }    
    return 0;       
}
