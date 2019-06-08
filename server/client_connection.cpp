#include "client_connection.h"

int client_connection::set_connection(char *server_addr){
	if(connection == 1)
		return -1;
	int server_len;
	struct sockaddr_in server_address;
	
	omp_set_nested(1);//打開openmp 巢狀執行緒 參考資料 https://www.phototalks.idv.tw/academic/?p=1997 
	// 註冊 Winsock DLL
	WSADATA wsadata;
	if(WSAStartup(0x101,(LPWSADATA)&wsadata) != 0) {
		printf("Winsock Error\n");
		exit(1);                                         
	}
	
	// 產生 server socket
	do{
		if(server_sockfd != SOCKET_ERROR)
			closesocket(server_sockfd);
		server_sockfd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET(使用IPv4); SOCK_STREAM; 0(使用預設通訊協定，即TCP)
		if(server_sockfd == SOCKET_ERROR) {
			printf("Socket Error\n");
			continue;
		}
		
		server_address.sin_family = AF_INET; // AF_INT(使用IPv4)
		//server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // 設定IP位址
		//server_address.sin_addr.s_addr = inet_addr("122.116.195.140"); // 設定IP位址
		server_address.sin_addr.s_addr = inet_addr(server_addr);
		server_address.sin_port = 60000; //設定埠號
		server_len = sizeof(server_address);
		
		if(bind(server_sockfd, (struct sockaddr *)&server_address, server_len) < 0) {
			printf("Bind Error\n");
			continue;
		}
		
		if(listen(server_sockfd, 5) < 0) {
			printf("Listen Error\n");
			continue;
		}
	}while(server_sockfd != SOCKET_ERROR);
	
	printf("伺服器等待使用者連入中...\n");
	do{
		int client_len;
		struct sockaddr_in client_address;
		
	    client_len = sizeof(client_address);
	    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
	}while(client_sockfd == SOCKET_ERROR);
    
	connection = true;
	return 1;
}

void client_connection::get_data(){
	
}

void client_connection::car_deconnect(){
	
}
		
int client_connection::get_direction(){
	return direction;
}

float client_connection::get_speed(){
	return speed;
}

bool client_connection::get_auto_mode(){
	return speed;
}

void client_connection::set_battery_level(float value){
	battery_level = value;
}

void client_connection::get_connection(){
	return connection;
}
