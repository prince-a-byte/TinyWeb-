# TinyWeb++

A lightweight HTTP web framework built completely from scratch in modern C++.

TinyWeb++ is an educational project focused on understanding how real backend frameworks work internally. Instead of hiding networking behind libraries, TinyWeb++ implements the HTTP server from the socket level upward.

The goal is to learn the architecture behind frameworks like Express, Flask, Spring Boot, and ASP.NET by building each component step by step.

---

## Features

### Server

* TCP socket creation
* Socket binding
* Listening for incoming connections
* Client acceptance loop
* Error handling
* Object-oriented `Server` class

### Request

* Reads HTTP requests from a client socket
* Parses the HTTP request line
* Extracts:

  * HTTP Method
  * Request Path
  * HTTP Version
* Stores request headers (structure ready)
* Stores request body (structure ready)

### Architecture

```
Browser
    │
    ▼
TCP Connection
    │
    ▼
Server
    │
    ▼
Request
    │
    ▼
method
path
version
```

---

## Project Structure

```
TinyWeb++
│
├── include/
│   ├── server.h
│   └── request.h
│
├── src/
│   ├── server.cpp
│   ├── request.cpp
│   └── main.cpp
│
├── README.md
└── LICENSE
```

---

## Current Capabilities

* Accept TCP connections
* Receive HTTP requests
* Parse HTTP request line
* Extract method, path, and version
* Modular object-oriented architecture
* Clean separation of responsibilities

---

## Example

Incoming request:

```http
GET /about HTTP/1.1
Host: localhost:8000
User-Agent: Chrome
```

Parsed as:

```cpp
Request req(clientSocket);

std::cout << req.method;   // GET
std::cout << req.path;     // /about
std::cout << req.version;  // HTTP/1.1
```

---

## Design Philosophy

TinyWeb++ is built around the **Single Responsibility Principle**.

Each class has one clear responsibility.

| Class      | Responsibility                             |
| ---------- | ------------------------------------------ |
| `Server`   | Manage sockets and client connections      |
| `Request`  | Parse incoming HTTP requests               |
| `Response` | *(Coming Soon)* Generate HTTP responses    |
| `Router`   | *(Coming Soon)* Route requests to handlers |

This separation keeps the codebase modular, maintainable, and easy to extend.

---

## Roadmap

### Phase 1 – Core HTTP Server ✅

* [x] Socket creation
* [x] Bind
* [x] Listen
* [x] Accept clients
* [x] Server class

### Phase 2 – Request Parsing ✅

* [x] Request class
* [x] Parse request line
* [x] Extract method
* [x] Extract path
* [x] Extract HTTP version

### Phase 3 – Response System 🚧

* [ ] Response class
* [ ] HTTP response builder
* [ ] Status codes
* [ ] Content-Type support

### Phase 4 – Router

* [ ] Route registration
* [ ] Static routes
* [ ] Dynamic routes
* [ ] Route parameters

### Phase 5 – Middleware

* [ ] Middleware pipeline
* [ ] Logging
* [ ] Authentication hooks

### Phase 6 – Advanced Features

* [ ] Static file serving
* [ ] JSON responses
* [ ] Thread pool
* [ ] Keep-Alive connections
* [ ] HTTP POST support

---

## Why TinyWeb++?

Most tutorials teach developers how to *use* web frameworks.

TinyWeb++ is about learning how to **build** one.

By implementing each layer manually—from sockets to routing—you gain a deeper understanding of networking, HTTP, software architecture, and modern C++ design.

---

## Tech Stack

* C++17
* POSIX Sockets
* STL
* Object-Oriented Design

---

## License

This project is licensed under the MIT License.
