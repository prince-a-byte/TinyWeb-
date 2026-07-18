# TinyWeb-

A lightweight HTTP web framework built completely from scratch in Modern C++.

## Features

- HTTP/1.1 Server
- Routing
- Dynamic Routes
- Request & Response Objects
- Static File Serving
- Threaded Server
- JSON Responses
- Middleware
- Logging

## Example

```cpp
Server app;

app.get("/", [](Request req, Response res){
    res.send("<h1>Hello World</h1>");
});

app.listen(8000);
```