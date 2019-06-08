#include "clintconnect.h"

int clintconnect::main_(char *server_addr){
	int len;
	struct sockaddr_in address;
	int result;
	printf("Winsock Connectting\n");
	WSADATA wsadata;
	if (WSAStartup(0x101, (LPWSADATA)&wsadata) != 0)
	{
		printf("Winsock Error\n");
		return 1;
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	//address.sin_addr.s_addr = inet_addr("127.0.0.1");
	//address.sin_port = 60000;
	int a = inet_pton(AF_INET, server_addr, &address.sin_addr);
	address.sin_port = 60000; //設定埠號
	len = sizeof(address);
	printf("Connectting\n");
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result == -1)
	{
		printf("Connect Error");
		return 2;
	}
	Sleep(500);
	printf("伺服器已連接~~\n");
	char ch[100];
	sprintf(ch, "加入聊天室");
	buffer = (char)(strlen(ch) + 1);
	ch[buffer - 1] = '\0';
	send(sockfd, &buffer, 1, 0);
	send(sockfd, ch, buffer, 0);
	/*#pragma omp parallel sections 
	{
		#pragma omp section
		{
			send_cmd(sockfd);
		}
		#pragma omp section
		{
			recv_cmd(sockfd);
		}
	}*/
	return 0;
	//closesocket(sockfd);
}

int clintconnect::send_cmd(char *ch1)
{
	char *ch;
	ch = (char*)malloc(sizeof(char) * strlen(ch1));
	sprintf(ch, "%s", ch1);
	buffer = (char)(strlen(ch) + 1);
	ch[buffer - 1] = '\0';
	send(sockfd, &buffer, 1, 0);
	send(sockfd, ch, buffer, 0);
	return 0;
}

void clintconnect::recv_cmd()
{
	while (1) {
		char *ch;
		buffer = 0;
		recv(sockfd, &buffer, 1, 0);
		if (buffer <= 0)
			exit(0);
		//printf("buffer = %d\n", buffer);
		ch = (char*)malloc(sizeof(char)*buffer);
		recv(sockfd, ch, buffer, 0);
		//printf("char from server = %s\n", ch);
		printf("%s\n", ch);
		//system("pause");
		free(ch);
	}
}

void clintconnect::close() {
	closesocket(sockfd);
}