#include "MyForm.h"


class clintconnect{
	public:
		int main_(char *server_addr);
		int send_cmd(char *ch1);
		void recv_cmd();
		void close();
	private:
		SOCKET sockfd;
		char buffer;
};