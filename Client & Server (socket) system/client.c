#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

//pass two arguments to main, when main is called. argc = arguments count,
// s a pointer to an array of character strings that contain the arguments, one per string.
int main(int argc, char *argv[]) {
	int sock = 0;
	int num = 0;
	char buff[1024];
	const int port = 12345;
	struct sockaddr_in serv_addr;

	if (argc != 2) {
		printf("\n Usage: %s <ip of server> \n", argv[0]);
		return 1;
	}

	memset(buff, '0', sizeof(buff));
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n ERROR : Could not create a socket \n")
		return 1;
	}

	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
		printf("\n inet_pton error occured \n");
		return 1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("\n ERROR : connect failed \n");
		return 1;
	}

	while ((num = read(sock, buff, sizeof(buff)-1)) > 0) {
		buff[num] = 0;
		if(fputs(buff, stdout) == EOF) {
			printf("\n ERROR : fputs error\n");
		}
	}

	if(n < 0) {
		printf("\n Read error \n");
	}

	return 0;
}
