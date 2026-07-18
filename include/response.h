#pragma once

#include <string>
#include <unordered_map>

class Response
{
    public:
        explicit Response(int clientSocket);
        void send(const std::string& body);
        void setHeader(const std::string& key, const std::string& value);

    private:
        int clientSocket;
        std::string status;
        std::unordered_map<std::string, std::string> headers;

};