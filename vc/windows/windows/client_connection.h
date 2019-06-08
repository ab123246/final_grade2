#include <omp.h>
#include <iostream>
#include <String.h>

#include <WS2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
#pragma comment(lib, "Ws2_32.lib") 

class client_connection{
	private:
		int direction = 0; 
		double speed = 0;
		bool auto_mode = false;
		double battery_level;
		bool server_connection = false;
		bool client_connection_ = false;
		
		SOCKET client_sockfd = SOCKET_ERROR;
		SOCKET server_sockfd = SOCKET_ERROR;
	public:
    	int set_connection(char *server_addr);
		int wait_connection();
		int close_server_connection();
		char* get_data();
		
		void send_(int car_speed, double car_direction, double car_battery_level);

		int get_direction();
		float get_speed();
		bool get_auto_mode();
		void set_battery_level(float value);
		bool get_server_connection();
		bool get_client_connection();
};
