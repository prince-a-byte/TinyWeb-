#pragma once

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "router.h"

class Server
{
    private:
        int serverSocket;
        int port;
        sockaddr_in address;
        Router router;

        bool createSocket();
        void createAddress();
        bool bindSocket();
        bool listenSocket();
        void acceptClient();
        bool initialize();

    public:
        explicit Server(int port)
            : port(port)

        {

        }
        
        void start();
        void get(const std::string& url, std::function<void(Request& req, Response& res)> handler);

};

