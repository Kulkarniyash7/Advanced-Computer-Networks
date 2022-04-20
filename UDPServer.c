#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main(int argc, char const *argv[])
{
	int server_sockfd;
	server_sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	
	struct sockaddr_in server_addr, client_addr;
	int clientsize=sizeof(client_addr);
	char recv_data[100], send_data[100];
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(50055);
	server_addr.sin_addr.s_addr=inet_addr("192.168.125.178");
	bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	
	recvfrom(server_sockfd, recv_data, sizeof(recv_data), 0, (struct sockaddr *)&client_addr, &clientsize);
	printf("\n%s", recv_data);
	
	printf("\nEnter your data: ");
	scanf("%s",send_data);
	sendto(server_sockfd, send_data, sizeof(send_data), 0, (struct sockaddr *)&client_addr, clientsize);
	
}
