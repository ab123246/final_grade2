#include "socket_connection.h"
#include "sys/socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void socket_connection::send_socket()
{
	sprintf(send_message,"%d %d %d%c",speed,direction,battery_level,'\0');
	char message_length = strlen(send_message)+1;
	send(sockfd,&message_length,1,0);
	send(sockfd,send_message,message_length,0);
}

void socket_connection::receive_socket()
{
	char receiveMessage[100]={};
	recv(sockfd,receiveMessage,sizeof(receiveMessage),0);
	printf("%s",receiveMessage);
}

void socket_connection::communicating()
{
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			send_socket();
		}
		#pragma omp section
		{
			//receive_socket();
		}
	}
}

int socket_connection::create_connection()
{
	speed = 10;
	direction = 50;
	battery_level = 40;
	char ip[16];
	printf("Enter IP address that's ready to connect : ");
	scanf("%s",ip);
	
	sockfd=0;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
		printf("Fail to connect a socket\n");
	else
		printf("socket connet successful..\n");
	
	struct sockaddr_in info;
	bzero(&info,sizeof(info));
	info.sin_family=PF_INET;
	
	inet_aton(ip,&info.sin_addr);
	//info.sin_addr.s_addr=inet_addr(ip);
	info.sin_port=60001;
	printf("Connecting....\n");
	int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
	if(err == -1)
		printf("Connect to Server Failed!!");
	return 0;
}
