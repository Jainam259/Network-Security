#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
using namespace std;
#define PORT 8080
#define SIZE 1024

int main()
{
    struct sockaddr_in address, clientAddress;

    socklen_t clientSize = sizeof(clientAddress); // clientSize is variable so name change kr skte hai

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0); // generally sockfd use hota hai but to understand easily use any name like serverSocket etc

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT); // you can simply write PORT but it is recommended to write in htons()
    address.sin_addr.s_addr = INADDR_ANY;
    bind(serverSocket, (struct sockaddr *)&address, sizeof(address));
    listen(serverSocket, 5);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientSize); // accept krne se client k saath connect hoga aur connection ko var mein store krna hoga isse aage message recieve krne mein help hogi ab serverSocket use nahi hoga
    FILE *fp;
    fp = fopen("recievedFile.txt", "w"); // recievedFile.txt is a file name, if file does not exist then it will be created, it's better to open file in wb instead of a on server side
    // sendFile(clientSocket, f);
    char data[SIZE];
    while (1)
    {
        int recievedBytes = recv(clientSocket, data, sizeof(data), 0);
        if (recievedBytes <= 0)
        {
            break; // if no data is received then break the loop
        }
        fwrite(data, 1, recievedBytes, fp); // data mein jo store hua hai wo ab recievedFile.txt mein write hoga or store hoga isliye fp(filePointer diya hai)
        bzero(data, SIZE);
    }
    // recv(clientSocket, buffer, SIZE, 0); // SIZE is variable which contains size of buffer its value is generally 1024 to bs uper define kr dia
    // cout << "Message from client: " << buffer << endl;
    close(serverSocket);
    close(clientSocket);
    fclose(fp);
}