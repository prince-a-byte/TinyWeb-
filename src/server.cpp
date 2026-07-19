#include "server.h"
#include "request.h"
#include "response.h"

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

        Request req(clientSocket);

        std::cout<<"Method: "<<req.method<<'\n';
        std::cout<<"Path: "<<req.path<<'\n';
        std::cout<<"Version: "<<req.version<<'\n';

        Response res(clientSocket);

        router.route(req,res);

        close(clientSocket);

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

void Server::get(const std::string& url, std::function<void(Request& req, Response& res)> handler)
{
    router.get(url,handler);
}