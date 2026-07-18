#include "request.h"
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>


void Request::parseHeaders() {}

void Request::parseBody() {}

void Request::parseRequest(int clientSocket)
{
    constexpr std::size_t BUFFER_SIZE = 4096;
    char buffer[BUFFER_SIZE + 1];

    ssize_t byteRecived = recv(clientSocket, buffer, BUFFER_SIZE, 0);

    if(byteRecived <= 0)
    {
        std::cerr<<"Connection Failed!\n";
        return;
    }

    buffer[byteRecived] = '\0';

    std::string request(buffer);

    std::size_t startpos = request.find("\r\n");
    
    if(startpos == std::string::npos)
    {
        return;
    }

    std::string firstLine = request.substr(0, startpos);

    parseRequestLine(firstLine);

}

void Request::parseRequestLine(const std::string &firstLine)
{
    std::stringstream ss(firstLine);

    ss>>method>>path>>version;

}

Request::Request(int clientSocket)
{
    parseRequest(clientSocket);
}