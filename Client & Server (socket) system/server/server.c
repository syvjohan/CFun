#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
 
int main(int argc , char *argv[])
{
    int socketD , clientSock , conn , readSize;
    struct sockaddr_in server , client;
    char clientMessage[1024];
    const int port = 12345;
     
    //Create socket
    socketD = socket(AF_INET , SOCK_STREAM , 0);
    if (socketD == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
     
    //Bind
    if( bind(socketD,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error: ");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socketD , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    conn = sizeof(struct sockaddr_in);
     
    //accept connection from an incoming client
    clientSock = accept(socketD, (struct sockaddr *)&client, (socklen_t*)&conn);
    if (clientSock < 0)
    {
        perror("accept failed. Error: ");
        return 1;
    }
    puts("Connection accepted");

    //Receive a message from client
    while((readSize = recv(clientSock , clientMessage , 1024 , 0)) > 0)
    {
        //Send the message back to client
        write(clientSock , clientMessage , strlen(clientMessage));
        //empty array with messages
        memset(&clientMessage[0], 0, sizeof(clientMessage));
    }
     
    if(readSize == 0)
    {
        puts("Client disconnected");
    }
    else if(readSize == -1)
    {
        perror("recv failed. Error: ");
    }
     
    return 0;
}