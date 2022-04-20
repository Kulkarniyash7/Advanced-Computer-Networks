#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main()
{
	int client_sockfd;
	client_sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	
	struct sockaddr_in server_addr;
	int serversize=sizeof(server_addr);
	char recv_data[100], send_data[100];
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(50055);
	server_addr.sin_addr.s_addr=inet_addr("192.168.125.178");
	
	printf("\nEnter your data: ");
	scanf("%s",send_data);
	sendto(client_sockfd, send_data, sizeof(send_data), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
	
	recvfrom(client_sockfd, recv_data, sizeof(recv_data), 0, (struct sockaddr *)&server_addr, &serversize);
	printf("\n%s", recv_data);
	
	close(client_sockfd);
}
