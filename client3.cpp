// client async

#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int main() {
    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying server address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // connecting to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        cout << "Connection failed!" << endl;
        return -1;
    }

    // sending data to the server
    const char* message = "Hello, server!";
    send(clientSocket, message, strlen(message), 0);

    // receiving response from the server
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from server: " << buffer << endl;

    // closing the client socket
    close(clientSocket);
    return 0;
}
