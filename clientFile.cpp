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
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0); // generally sockfd use hota hai but to understand easily use any name like clientSocket etc
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;
    int connectingServer = connect(clientSocket, (struct sockaddr *)&address, sizeof(address));
    if (connectingServer < 0)
    {
        // cerr<<"Error connecting server"
        cerr << "Kuch to gadbad hai" << endl;
    }
    FILE *fp;
    fp = fopen("client.cpp", "r"); // it's better to open file in rb instead of a on client side
    if (fp == NULL)
    {
        perror("File is empty");
        exit(0);
    }
    char data[SIZE];
    while (int bytesRead = fread(data, 1, sizeof(data), fp)) // fread() reads data from fp(filePointer) and transfer it to variable named data, jb tk file poori read nahi hogi ya datatransfer nahi hoga tb tk loop chalegi
    {
        // bytesRead fread se jo bytes read hote hai usko store krta hai
        int sendingData = send(clientSocket, data, bytesRead, 0); // recommended to use bytesRead so that exact count of bytes to send is known else it will print some strange chars

        if (sendingData < 0) //<0 ya to ==-1 kr skte hai
        {
            cerr << "Error sending data" << endl;
        }
        bzero(data, SIZE); // after printing or copying line for the new line it clears previous data and again set it to 0
    }
    // sendFile(clientSocket, f);
    // const char *msg = "Hello everybody";
    // send(clientSocket, msg, strlen(msg), 0);
    close(clientSocket);
    fclose(fp);
    return 1;

}