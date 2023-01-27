/*------------------------------------------------------------------------------ 
   *
    *   Author         : Emertxe (http://www.emertxe.com) 
     *   Date           : Tue 01 Mar 2016 16:18:10 IST
      *   File           : t020.c
       *   Title          : IPC mechanism - Usage of TCP socket - Server
        *   Description    : Sockets offer interfaces with TCP/IP stack inside Linux 
	 *                    Kernel, using which remote connections can be established
	  *                    over a network. This program demonstrates various steps
	   *                    to establish successful three-way handshake as a server. 
	    *
	     *----------------------------------------------------------------------------*/
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define SERVER_IP       "127.0.0.1"
#define SERVER_PORT 	1500
#define SERVER_LENGTH 	10
#define SERVER_BUFF	20

int main()
{
    char ch[1];
    int sock_fd, data_sock_fd,buffer_len;
    struct sockaddr_in serv_addr; 
    int buff[10];
     char buff1[10] = "2000";
    char serv_buffer[SERVER_BUFF];
    printf("Emertxe: Server is waiting...\n");
    /* Create a TCP socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    /* Bind it to a particular IP address & port) */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(SERVER_PORT); 
    bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
    /* listen for incoming connections */
    listen(sock_fd, SERVER_LENGTH);
    /* If there are any, accept and create a new data socket */
    data_sock_fd = accept(sock_fd, (struct sockaddr*)NULL, NULL); 
    memset(serv_buffer, 0, sizeof(serv_buffer));
    /* Try to get some actual data from client */
    recv(data_sock_fd, (void *)ch,1,0);
//    char ch1 = *;
    /*unsigned char sec = '+';
   switch(sec)
    {
	case '+' :
	//buff1 = 2000;*/
    if(strcmp(ch,"+")==0)
    {
	send(sock_fd,buff1,strlen(buff1)+1,0); 
	printf("send to client\n");

	    //break;



    }
    /* Print the data received from client */
    printf("Here is the client data: %s\n",serv_buffer);
    /* Close the sockets now */
    close(data_sock_fd);
    close(sock_fd);
}

