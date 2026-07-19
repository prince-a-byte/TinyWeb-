#include "server.h"

int main()
{
    Server app(8000);

    app.get("/", [](Request& req, Response& res){
        res.send("<h1>Welcome to the TinyWeb++ FrameWork</h1>");
    });

    app.get("/home", [](Request& req, Response& res){
        res.send("<h1>Welcome the Home Page</h1>");
    });

    app.start();

    return 0;
}