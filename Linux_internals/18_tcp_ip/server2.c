

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
#define SERVER_PORT 	2500
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
    recv(data_sock_fd, (void *)serv_buffer,SERVER_BUFF,0);
    printf("%s",serv_buffer);
    int num2 = atoi(&serv_buffer[0]);
    int num3 = atoi(&serv_buffer[2]);
    printf("%d %d",num2,num3);
    int num1 = num2 - num3;
    snprintf(buff1,10,"%d\n",num1);
    send(data_sock_fd,buff1,strlen(buff1)+1,0); 
    printf("send to client\n");
    close(data_sock_fd);
    close(sock_fd);
}
