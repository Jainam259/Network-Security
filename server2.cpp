#include<iostream>
#include<cstring>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
using namespace std;

void Client(int clientSocket)
{
    // receving data
    char buffer[1024] = {0};
    recv(clientSocket,buffer,sizeof(buffer),0);
    cout<<"Message from client : "<<buffer<<endl;

    // sending data
    const char* response = "Hello Client!";
    send(clientSocket,response,strlen(response),0);

    close(clientSocket);
}

int main()
{
    int serverSocket = socket(AF_INET,SOCK_STREAM,0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress));

    listen(serverSocket,5);

    while(true)
    {
        int clientSocket = accept(serverSocket,nullptr,nullptr);
        Client(clientSocket);
    }

    close(serverSocket);
    return 0;
}