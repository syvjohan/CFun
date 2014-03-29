#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1024] , serverReply[1024];
    const int port = 12345;
    const char ip[10] = "127.0.0.1";
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    printf("Socket created\n");
     
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    printf("Connected\n");
     
    //keep communicating with server
    while (1)
    {
    	memset(&message[0], 0, sizeof(message));
        printf("Enter message : ");
        scanf("%s" , message);
         
        //Send some data
        if (send(sock , message , strlen(message) , 0) < 0)
        {
            printf("Send failed");
            return 1;
        }
        
        //Empty char[] 
        memset(&serverReply[0], 0, sizeof(serverReply));
        //Receive a reply from the server
        if (recv(sock , serverReply , 1024, 0) < 0)
        {
            printf("recv failed");
            break;
        }
        puts("Received message: ");
        puts(serverReply);
    }
     
    close(sock);
    return 0;
}