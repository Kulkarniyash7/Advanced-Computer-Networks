#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main()
{
	int s_sockfd,a_sockfd;
	char recv_data[100],send_data[100];
	s_sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	
	
	struct sockaddr_in s_addr,c_addr;
	
	int client_length=sizeof(c_addr);
	
	s_addr.sin_family=AF_INET;
	s_addr.sin_port=htons(50010);
	s_addr.sin_addr.s_addr=inet_addr("192.168.125.177");
		
	bind(s_sockfd,(struct sockaddr*)&s_addr,sizeof(s_addr));
	
		
	recvfrom(s_sockfd,recv_data,sizeof(recv_data),0,(struct sockaddr*)&c_addr,&client_length);
		
	printf("Received Data is: %s",recv_data);
		
	printf("Enter Your Data :");
		
	scanf("%s",send_data);
		
	sendto(s_sockfd,send_data,sizeof(send_data),0,(struct sockaddr*)&c_addr,sizeof(c_addr));
		
		

}
