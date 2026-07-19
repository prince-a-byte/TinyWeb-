#include "router.h"

Router::Router() = default;

void Router::get(const std::string& url, std::function<void(Request&,Response&)> handler)
{
    routes[url] = handler;
}

void Router::route(Request& req, Response& res)
{
    auto it = routes.find(req.path);
    if(it != routes.end()){
        it->second (req, res);
    }
    else{
        res.send("<h1>Error 404 Not Found</h1>");
    }
}