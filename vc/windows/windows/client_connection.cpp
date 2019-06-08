#include "client_connection.h"

int client_connection::set_connection(char *server_addr){
	if(server_connection == 1)
		return -1;
	int server_len;
	struct sockaddr_in server_address;
	
	//omp_set_nested(1);//打開openmp 巢狀執行緒 參考資料 https://www.phototalks.idv.tw/academic/?p=1997 
	// 註冊 Winsock DLL
	WSADATA wsadata;
	if(WSAStartup(0x101,(LPWSADATA)&wsadata) != 0) {
		printf("Winsock Error\n");
		return -2;
	}
	
	// 產生 server socket
	do{
		if(server_sockfd != SOCKET_ERROR)
			closesocket(server_sockfd);
		server_sockfd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET(使用IPv4); SOCK_STREAM; 0(使用預設通訊協定，即TCP)
		if(server_sockfd == SOCKET_ERROR) {
			printf("Socket Error\n");
			return -2;
		}
		
		server_address.sin_family = AF_INET; // AF_INT(使用IPv4)
		//server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // 設定IP位址
		//server_address.sin_addr.s_addr = inet_addr("122.116.195.140"); // 設定IP位址
		int a = inet_pton(AF_INET, server_addr, &server_address.sin_addr);
		server_address.sin_port = 60000; //設定埠號
		server_len = sizeof(server_address);
		
		if(bind(server_sockfd, (struct sockaddr *)&server_address, server_len) < 0) {
			printf("Bind Error\n");
			return -3;
		}
		
		if(listen(server_sockfd, 5) < 0) {
			printf("Listen Error\n");
			return -3;
		}
	}while(server_sockfd == SOCKET_ERROR);
	client_sockfd = SOCKET_ERROR;
	server_connection = true;
	return 20;
}

int client_connection::wait_connection() {
	
	if (client_sockfd != SOCKET_ERROR)
		return -1;
	printf("伺服器等待使用者連入中...\n");
	int client_len;
	struct sockaddr_in client_address;

	client_len = sizeof(client_address);
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
	if (client_sockfd != SOCKET_ERROR) {
		client_connection_ = true;
		return 1;
	}else
		return 0;
}

int client_connection::close_server_connection() {
	if(server_connection == true){
		closesocket(server_sockfd);
		server_sockfd = NULL;
		closesocket(client_sockfd);
		client_sockfd = NULL;
		client_connection_ = false;
		server_connection = false;
		return 1;
	}else
		return 0;
}

char* client_connection::get_data(){
	if (client_connection_ && client_sockfd != SOCKET_ERROR) {
		char *ch;
		char buffer = 0;
		int mode;
		mode = recv(client_sockfd, &buffer, 1, 0);
		if (buffer <= 0){
			closesocket(client_sockfd);
			client_sockfd = SOCKET_ERROR;
			client_connection_ = false;
			char a[2] = {-1,'\0'};
			return a;
		}
		ch = (char*)malloc(sizeof(char)*buffer);
		recv(client_sockfd, ch, buffer+1, 0);
		int index = 0, str_index = 0;
		char str_buffer[10];
		double map[3];
		for (int loopnum1 = 0; index < 3 && ch[loopnum1] != '\0'; loopnum1++) {
			if (ch[loopnum1] != ' ') {
				str_buffer[str_index] = ch[loopnum1];
				str_buffer[str_index + 1] = '\0';
				str_index++;
			}
			else {
				map[index] = atof(str_buffer);
				index++;
				str_index = 0;
			}
		}
		speed = map[0];
		direction = map[1];
		battery_level = map[2];
		return ch;
	}
	char a = -1;
	return &a;
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

void client_connection::send_(int car_speed,double car_direction,double car_battery_level){
	char *ch;
	char buffer;
	ch = (char*)malloc(sizeof(char) * 200);
	sprintf(ch, "%d %lf %lf ", car_speed, car_direction, car_battery_level);
	buffer = (char)(strlen(ch) + 1);
	ch[buffer - 1] = '\0';
	send(client_sockfd, &buffer, 1, 0);
	send(client_sockfd, ch, buffer, 0);
}

void client_connection::set_battery_level(float value){
	battery_level = value;
}

bool client_connection::get_server_connection(){
	return server_connection;
}

bool client_connection::get_client_connection() {
	return client_connection_;
}
