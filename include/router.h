#pragma once
#include <unordered_map>
#include <string>
#include <functional>
#include "request.h"
#include "response.h"


class Router
{
    public:
        Router();
    
        void get(const std::string& url, std::function<void(Request&, Response&)> handler);
        void post(const std::string& url, std::function<void(Request&, Response&)> handler);
        void route(Request& req, Response& res);
    
    private:
 
        std::unordered_map<std::string, std::function<void(Request&, Response&)>> routes;
};