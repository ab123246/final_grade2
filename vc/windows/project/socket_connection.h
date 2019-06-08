class socket_connection{
	private:
		int speed;
		int direction;
		int battery_level;
		
		char send_message[255];
		int sockfd;
		void receive_socket();
	public:
		int create_connection();
		void communicating();
		void send_socket();
};
