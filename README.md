# TinyWeb++

> A lightweight HTTP web framework built from scratch in Modern C++.

TinyWeb++ is an educational web framework that demonstrates how real frameworks such as Express.js, Flask, Crow, and Drogon work internally. It is built directly on top of POSIX sockets without relying on external networking libraries.

---

## ✨ Features

- TCP server implementation
- HTTP request parsing
- HTTP response generation
- Route registration
- Dynamic request routing
- Lambda-based request handlers
- Simple and clean API
- Modular architecture

---

## Example

```cpp
#include "server.h"

int main()
{
    Server app(8080);

    app.get("/", [](Request& req, Response& res)
    {
        res.send("<h1>Welcome to TinyWeb++</h1>");
    });

    app.get("/about", [](Request& req, Response& res)
    {
        res.send("<h1>About TinyWeb++</h1>");
    });

    app.start();

    return 0;
}
```

Open your browser:

```
http://localhost:8080/
```

---

## Project Structure

```
TinyWeb++
│
├── include/
│   ├── server.h
│   ├── router.h
│   ├── request.h
│   └── response.h
│
├── src/
│   ├── server.cpp
│   ├── router.cpp
│   ├── request.cpp
│   ├── response.cpp
│   └── main.cpp
│
├── README.md
└── CMakeLists.txt
```

---

## Architecture

```
Browser
    │
    ▼
+----------------+
|     Server     |
+----------------+
        │
        ▼
+----------------+
|     Router     |
+----------------+
        │
        ▼
 Route Handler
        │
        ▼
+----------------+
|    Response    |
+----------------+
```

Request Flow:

```
Browser
    │
    ▼
Server
    │
    ▼
Request Parser
    │
    ▼
Router
    │
    ▼
Route Handler
    │
    ▼
Response
    │
    ▼
Browser
```

---

## Components

### Server

Responsible for:

- Creating sockets
- Binding
- Listening
- Accepting clients
- Delegating requests to the Router

---

### Request

Responsible for:

- Parsing HTTP requests
- Extracting
  - Method
  - Path
  - HTTP Version
  - Headers
  - Body

---

### Response

Responsible for:

- Building HTTP responses
- Sending data to clients
- Managing response headers

---

### Router

Responsible for:

- Registering routes
- Finding matching routes
- Executing request handlers
- Returning 404 responses when no route exists

---

## Build

```bash
mkdir build
cd build

cmake ..
make
```

Or compile manually

```bash
g++ src/*.cpp -Iinclude -std=c++17 -o TinyWeb
```

Run

```bash
./TinyWeb
```

---

## Current Features

- [x] TCP Socket Server
- [x] HTTP Request Parsing
- [x] HTTP Response Generation
- [x] GET Routing
- [x] Lambda Route Handlers
- [x] Basic 404 Handling

---

## Roadmap

### Version 0.3

- POST routing
- Route parameters
- Query parameters
- Static file serving

---

### Version 0.4

- Middleware
- Logger
- Better HTTP status handling
- Response helper functions

---

### Version 0.5

- JSON support
- Thread pool
- Connection keep-alive
- Configuration system

---

## Learning Goals

TinyWeb++ was created to understand how modern web frameworks are built internally.

Instead of hiding networking behind libraries, TinyWeb++ starts with raw sockets and incrementally builds:

- HTTP
- Routing
- Framework architecture
- Middleware
- Static file serving
- JSON APIs

---

## License

MIT License
