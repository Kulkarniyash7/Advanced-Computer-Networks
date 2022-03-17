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

int sockfd,acc_sockfd;
sockfd=socket(AF_INET,SOCK_STREAM,0);

struct sockaddr_in server_addr,client_addr;
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(50008);
server_addr.sin_addr.s_addr=inet_addr("192.168.125.175");

char recv_data[100],send_data[100];
printf("binding address to socket\n");

bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));

printf("Listening to socket \n");

listen(sockfd,10);

//while(1)
//{
int clientlength=sizeof(client_addr);
printf("Waiting for client connection request...\n");

acc_sockfd=accept(sockfd,(struct sockaddr *)&client_addr,&clientlength);

printf("client connection request received...\n");
printf( "Client address: %s\n", inet_ntoa(client_addr.sin_addr));
printf("Waiting for data from client...\n");
recv(acc_sockfd,recv_data,sizeof(recv_data),0);
printf ("Received Data is %s",recv_data);
printf ("\nEnter Data : \t");
scanf("%s",send_data);
send(acc_sockfd,send_data,sizeof(send_data),0);
//}
close(acc_sockfd);
close(sockfd);
}
