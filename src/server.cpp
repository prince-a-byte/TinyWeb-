#include "server.h"

bool Server::createSocket()
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket == -1){
        std::cerr<<"Socket Creation Failed!\n";
        return false;
    }

    return true;
}

void Server::createAddress()
{
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
}

bool Server::bindSocket()
{
    if(bind(serverSocket, (sockaddr*) &address, sizeof(address)) == -1){
        std::cerr<<"Binding Failed Check Your Code!\n";
        close(serverSocket);
        return false;
    }

    return true;
}

bool Server::listenSocket()
{
    if(listen(serverSocket,5) == -1){
        std::cerr<<"Listening Failed!\n";
        close(serverSocket);
        return false;
    }

    return true;
}


void Server::acceptClient()
{
    while(true)
    {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if(clientSocket == -1){
            std::cerr<<"Client Connection Failed!\n";
            break;
        }

        else{
            std::cout<<"Client Connected Successfully!\n";
        }

    }

    close(serverSocket);
}

void Server::start(){

    if(!initialize()) return;
        
    acceptClient();
        

}

bool Server::initialize()
{
    if(!createSocket()) return false;
        
    createAddress();
        
    if(!bindSocket()) return false;
        
    if(!listenSocket()) return false;

    return true;
}

int main()
{
    Server app(8000);

    app.start();

    return 0;
}