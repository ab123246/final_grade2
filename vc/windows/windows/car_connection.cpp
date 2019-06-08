#include "car_connection.h"

int car_connection::set_connection(char *server_addr) {
	if (server_connection == 1)
		return -1;
	int server_len;
	struct sockaddr_in server_address;

	//omp_set_nested(1);//���}openmp �_������� �ѦҸ�� https://www.phototalks.idv.tw/academic/?p=1997 
	// ���U Winsock DLL
	WSADATA wsadata;
	if (WSAStartup(0x101, (LPWSADATA)&wsadata) != 0) {
		printf("Winsock Error\n");
		return -2;
	}

	// ���� server socket
	do {
		if (server_sockfd != SOCKET_ERROR)
			closesocket(server_sockfd);
		server_sockfd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET(�ϥ�IPv4); SOCK_STREAM; 0(�ϥιw�]�q�T��w�A�YTCP)
		if (server_sockfd == SOCKET_ERROR) {
			printf("Socket Error\n");
			return -2;
		}

		server_address.sin_family = AF_INET; // AF_INT(�ϥ�IPv4)
		//server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // �]�wIP��}
		//server_address.sin_addr.s_addr = inet_addr("122.116.195.140"); // �]�wIP��}
		int a = inet_pton(AF_INET, server_addr, &server_address.sin_addr);
		server_address.sin_port = 60001; //�]�w��
		server_len = sizeof(server_address);

		if (bind(server_sockfd, (struct sockaddr *)&server_address, server_len) < 0) {
			printf("Bind Error\n");
			return -3;
		}

		if (listen(server_sockfd, 5) < 0) {
			printf("Listen Error\n");
			return -3;
		}
	} while (server_sockfd == SOCKET_ERROR);
	car_sockfd = SOCKET_ERROR;
	server_connection = true;
	return 20;
}

int  car_connection::wait_connection() {
	if (car_sockfd != SOCKET_ERROR)
		return -1;
	printf("���A�����ݨϥΪ̳s�J��...\n");
	int car_len;
	struct sockaddr_in car_address;

	car_len = sizeof(car_address);
	car_sockfd = accept(server_sockfd, (struct sockaddr *)&car_address, &car_len);
	if (car_sockfd != SOCKET_ERROR) {
		car_connection_ = true;
		return 1;
	}else
		return 0;
}

int  car_connection::close_server_connection() {
	if (server_connection == true) {
		closesocket(server_sockfd);
		server_sockfd = NULL;
		closesocket(car_sockfd);
		car_sockfd = NULL;
		car_connection_ = false;
		server_connection = false;
		return 1;
	}
	else
		return 0;
}

char*  car_connection::get_data() {
	if (car_connection_ && car_sockfd != SOCKET_ERROR) {
		char *ch;
		char buffer = 0;
		int mode;
		mode = recv(car_sockfd, &buffer, 1, 0);
		if (buffer <= 0) {
			closesocket(car_sockfd);
			car_sockfd = SOCKET_ERROR;
			car_connection_ = false;
			char a[2] = { -1,'\0' };
			return a;
		}
		ch = (char*)malloc(sizeof(char)*buffer);
		recv(car_sockfd, ch, buffer, 0);
		int index = 0,str_index = 0;
		char str_buffer[10];
		double map[3];
		for (int loopnum1 = 0; index < 3 && ch[loopnum1] != '\0';loopnum1++) {
			if (ch[loopnum1] != ' ') {
				str_buffer[str_index] = ch[loopnum1];
				str_buffer[str_index + 1] = '\0';
				str_index++;
			}else {
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

void car_connection::send_(int car_speed, double car_direction, double car_battery_level) {
	char *ch;
	char buffer;
	ch = (char*)malloc(sizeof(char) * 200);
	sprintf(ch, "%d %.2lf %.2lf ", car_speed, car_direction, car_battery_level);
	buffer = (char)(strlen(ch) + 1);
	ch[buffer - 1] = '\0';
	send(car_sockfd, &buffer, 1, 0);
	send(car_sockfd, ch, buffer, 0);
}

int  car_connection::get_direction() {
	return direction;
}

float  car_connection::get_speed() {
	return speed;
}

bool  car_connection::get_auto_mode() {
	return auto_mode;
}

float  car_connection::get_battery_level() {
	return battery_level;
}

bool  car_connection::get_server_connection() {
	return server_connection;
}

bool  car_connection::get_car_connection() {
	return car_connection_;
}