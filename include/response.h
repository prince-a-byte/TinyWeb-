#pragma once

#include <string>
#include <unordered_map>
#include "http_status.h"
#include "response.h"

class Response
{
    public:
        explicit Response(int clientSocket);
        void send(const std::string& body);
        Response& status(const HttpStatus& status);
        Response& setHeader(const std::string& key, const std::string& value);

    private:
        int clientSocket;
        HttpStatus status_;
        std::unordered_map<std::string, std::string> headers;

};