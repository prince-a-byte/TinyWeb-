#pragma once
#include <string>
#include <unordered_map>

class Request
{
    public:
        std::string method;
        std::string path;
        std::string version;
        std::unordered_map<std::string, std::string> headers;
        std::string body;

    public:
        explicit Request(int clientSocket);

    private:
        void parseRequest(int clientSocket);
        void parseRequestLine(const std::string& line);
        void parseHeaders();
        void parseBody();
        
};