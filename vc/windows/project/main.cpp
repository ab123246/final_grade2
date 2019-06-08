#include "socket_connection.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	socket_connection sc;
	sc.create_connection();
	sc.communicating();
	while(1);
	return 0;
}
