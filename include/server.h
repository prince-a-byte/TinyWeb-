#pragma once

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Server
{
    private:
        int serverSocket;
        int port;
        sockaddr_in address;

        bool createSocket();
        void createAddress();
        bool bindSocket();
        bool listenSocket();
        void acceptClient();
        bool initialize();

    public:
        Server(int port){
            this->port = port;
        }
        
        void start();

};

