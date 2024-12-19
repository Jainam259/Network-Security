// simple message

#include<iostream>
#include<cstring>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
using namespace std;
int main()
{
    int clientSocket = socket(AF_INET,SOCK_STREAM,0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    connect(clientSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress));

    const char* message = "Hello Server!";
    send(clientSocket,message,strlen(message),0);

    char buffer[1024] = {0};
    recv(clientSocket,buffer,sizeof(buffer),0);
    cout<<"Message from Server = "<<buffer<<endl;

    close(clientSocket);
    // close(serverSocket);
    return 0;
}


// g++ client1.cpp -o client
// ./client


// Message from Server = 