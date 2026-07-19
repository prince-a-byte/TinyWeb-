#include "response.h"
#include <iostream>
#include <sys/socket.h>

Response::Response(int clientSocket)
    : clientSocket(clientSocket),
      status_(Status::OK)
{
    headers["Content-Type"] = "text/html";
}

Response& Response::status(const HttpStatus& status)
{
    status_ = status;
    return *this;
}

void Response::send(const std::string& body)
{
    std::string response = "HTTP/1.1 "+std::to_string(status_.code)+" "+ status_.message+"\r\n";
    headers["Content-Length"] = std::to_string(body.size());
    headers["Connection"] = "close";

    for(const auto& [key,value] : headers)
    {
        response += key + ": " + value +"\r\n";
    }

    response += "\r\n";

    response += body;


    if(::send(clientSocket, response.c_str(), response.size(), 0) == -1)
    {
        std::cerr<<"Failed to Sent the Message!\n";
        return;
    }

}

Response& Response::setHeader(const std::string& key, const std::string& value)
{
    headers[key] = value;
    return *this;
}