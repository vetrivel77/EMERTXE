/*
NAME		: VETRIVEL P
DATE		: 20/01/2023
DESCRIPTION	: Implement Terminal protocol using Sockets
SAMPLE I/O	AND O/P:
./relay 
INFO: created relay socket
LISTENING: relay server is listening
.............
ACCEPTED: relay server accepted connection﻿﻿

./server_plus 
INFO: created server socket
LISTENING: plus server is listening 
ACCEPTED: accepted a connection
Client data  : 10  20  +
Result is 30
Sending result to client...

./client
Enter num1: 10
Enter num2: 20
Enter arithmetic operator: +
INFO: Created relay socket
SUCCESS: relay connection successful
SERVER IP 127.0.0.1
SERVER PORT 6000
INFO: Created server socket
SUCCESS: Server connection successful
RESULT: 30

   */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define SERVER_IP_ADDRESS 	"127.0.0.1"
#define SERVER_PORT       	1500
#define CLIENT_BUFF_SIZE	20
int main()
{
    int sock_fd,sock_fd1,c_size,c_size1;
    char client_buff[CLIENT_BUFF_SIZE];
    char b;
    struct sockaddr_in serv_addr; 
    /* Create a client socket */
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
	printf("Error: Could not create socket\n");
	return 1;
    } 
    /* Binding with client socket is optional here */
    /* Populate it with server's address details */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT); 
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);
    /* Get the message from client */
    printf("Enter the message you want to sent to server:\n");
    //char ch2;  
    scanf("%s",client_buff);
    char buff[1] ;

    if(connect(sock_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) != 0)
    {
	perror("connect");
	printf("Error connecting to server\n");	
	close(sock_fd);																																					
	exit(1);

    }
    else

	printf("Connection successful\n");
    /* Send the message to server */
    c_size = send(sock_fd,client_buff,strlen(client_buff)+1,0);

    if(c_size > 0)
	printf("Message sent to server successsfully, please check\n");																											
    else
	printf("Error: Message send\n");
   // int fd = accept(sock_fd,(struct sockaddr*)NULL,NULL);
    char buff1[10];
    printf("frome server recived\n");
    recv(sock_fd,(void*)buff1,10,0);  // recive server address from agent
    printf("%s\n",buff1);
    close(sock_fd);
//    int *new_sport = (int*)(buff1);
   unsigned short int new = atoi(buff1);
   printf("Server port -> %d\n",new);
  //  unsigned short int new = 2000;
    if((sock_fd1 = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
	printf("Error: Could not create socket\n");
	return 1;
    } 
    serv_addr.sin_port = htons(new); 
    if(connect(sock_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) != 0)
    {
	perror("connect");
	printf("Error connecting to server\n");	
	close(sock_fd);																																					
	exit(1);

    }
    else

	printf("Connection successful\n");
    printf("%s",client_buff);
    /* Send the message to server */
 c_size1 = send(sock_fd1,client_buff,strlen(client_buff)+1,0); // send data to server

    if(c_size1 > 0)
	printf("Message sent to server successsfully, please check\n");																											
    else
	printf("Error: Message send\n");
    int fd = accept(sock_fd,(struct sockaddr*)NULL,NULL);  // recive result from sever
   char buff2[10];
 printf("frome server recived\n");
    recv(sock_fd1,(void*)buff2,10,0);
    printf("Result : %s -> %s \n",client_buff,buff2); // print result to terminal

    close(sock_fd1);
}

