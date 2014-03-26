#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

int main() {
	int listening = 0;
	int connect = 0;
	struct sockaddr_in serv_addr;

	time_t ticks;

	char buff[1025];

	//<sys/socket.h>
	// AF_INET This designates the address format that goes with the Internet namespace.
	//The SOCK_STREAM style is like a pipe. it operates over a connection with a particular remote socket, and transmits data reliably as a stream of bytes.
	listening = socket(AF_INET, SOCK_STREAM, 0);
	//<string.h>
	// copies the character c (an unsigned char) to the first n characters of the string pointed to by the argument str.
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(buff, '0', sizeof(buff));

	serv_addr.sin_family = AF_INET;
	// Alllows the program to run without knowing the ip-address.
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	// the port.
	serv_addr.sin_port = htons(12345);

	// binds the ip-address to the socket
	bind(listen, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	// specifies maximum number of client connections that server will queue for this listening socket.
	listen(listening, 10);

	while(1) {
		connect = accept(listening, (struct sockaddr*) NULL, NULL);

		ticks = time(NULL);
		//snprintf = redirects the output of printf to a buffer
		// ctime = returns a string representing the localtime based on the argument timer.
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		write(connect, buff, strlen(buff));

		close(connect);
		// sleep for one second. 
		// prevents resources from beeing wasted. 
		sleep(1);

	}
}