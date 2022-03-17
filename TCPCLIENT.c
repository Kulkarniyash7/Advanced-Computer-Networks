#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
int sockfd;
char send_data[100],recv_data[100];
sockfd=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in server_addr;
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(50008);
server_addr.sin_addr.s_addr=inet_addr("192.168.125.175");
connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
printf ("Enter Data : \t");
scanf("%s",send_data);
send(sockfd,send_data,sizeof(send_data),0);
recv(sockfd,recv_data,sizeof(recv_data),0);
printf ("\nReceived Data is %s",recv_data);
close(sockfd);
}
