#include <omp.h>
#include <iostream>
#include <String.h>

#include <WS2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
#pragma comment(lib, "Ws2_32.lib") 
class car_connection {
private:
	int direction = 0;
	double speed = 0;
	bool auto_mode = false;
	double battery_level = 10.53;
	bool server_connection = false;
	bool car_connection_ = false;

	SOCKET car_sockfd = SOCKET_ERROR;
	SOCKET server_sockfd = SOCKET_ERROR;
public:
	int set_connection(char *server_addr);
	int wait_connection();
	int close_server_connection();
	void send_(int car_speed, double car_direction, double car_battery_level);
	char* get_data();

	int get_direction();
	float get_speed();
	bool get_auto_mode();
	float get_battery_level();
	bool get_server_connection();
	bool get_car_connection();
};
