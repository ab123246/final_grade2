#include <omp.h>
#include <winsock2.h>
#include <iostream>

class client_connection{
	private:
		int direction;
		float speed;
		bool auto_mode;
		float battery_level;
		bool connection = false;
		SOCKET client_sockfd,server_sockfd;
	public:
    	int set_connection(char *server_addr);
		void get_data();
		void car_deconnect();
		
		int get_direction();
		float get_speed();
		bool get_auto_mode();
		void set_battery_level(float value);
		void get_connection();
		struct car {
	        int direction;
			float speed;
    	};
};
