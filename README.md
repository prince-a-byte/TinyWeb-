# 🚀 TinyWeb++

> A lightweight HTTP web framework built from scratch in Modern C++.

TinyWeb++ is an educational web framework that demonstrates how real backend frameworks like **Express**, **Flask**, and **ASP.NET Core** work internally.

Instead of hiding networking behind libraries, TinyWeb++ builds every layer step by step—from TCP sockets to HTTP parsing, routing, middleware, and beyond.

---

# ✨ Features

## ✅ Implemented

- TCP Socket Server
- HTTP Request Parsing
- HTTP Response Generation
- Automatic HTTP Headers
- Object-Oriented Design
- Clean Separation of Responsibilities

---

# 📂 Project Structure

```
TinyWeb++
│
├── include/
│   ├── server.h
│   ├── request.h
│   └── response.h
│
├── src/
│   ├── main.cpp
│   ├── server.cpp
│   ├── request.cpp
│   └── response.cpp
│
├── CMakeLists.txt
└── README.md
```

---

# 🏗 Architecture

```
Browser
    │
    ▼
 TCP Connection
    │
    ▼
+-----------+
|  Server   |
+-----------+
    │
    ▼
+-----------+
|  Request  |
+-----------+
    │
    ▼
Application Logic
    │
    ▼
+-----------+
| Response  |
+-----------+
    │
    ▼
 HTTP Response
    │
    ▼
Browser
```

---

# 📖 Current Components

## Server

Responsible for

- Creating sockets
- Binding sockets
- Listening for connections
- Accepting clients
- Managing the request-response lifecycle

---

## Request

Responsible for parsing incoming HTTP requests.

Currently extracts

- HTTP Method
- Request Path
- HTTP Version

Example

```
GET / HTTP/1.1
```

becomes

```cpp
request.method   // GET
request.path     // /
request.version  // HTTP/1.1
```

---

## Response

Responsible for generating valid HTTP responses.

Automatically adds

- Content-Type
- Content-Length
- Connection

Example

```cpp
Response response(clientSocket);

response.send("<h1>Hello TinyWeb++</h1>");
```

Generated response

```
HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: 26
Connection: close

<h1>Hello TinyWeb++</h1>
```

---

# 🚀 Building

Compile

```bash
g++ src/*.cpp -Iinclude -std=c++17 -o TinyWeb
```

Run

```bash
./TinyWeb
```

Open your browser

```
http://localhost:8080
```

*(Replace `8080` with the port configured in `main.cpp` if different.)*

---

# 🎯 Goals

TinyWeb++ is being developed incrementally.

Each feature is built from scratch to understand how web frameworks work internally.

---

# 🛣 Roadmap

## ✅ Phase 1 — HTTP Core

- [x] TCP Socket Server
- [x] Server Class
- [x] Request Class
- [x] Response Class
- [x] HTTP Request Parsing
- [x] HTTP Response Generation

---

## 🚧 Phase 2 — Routing

- [ ] Router
- [ ] GET Routes
- [ ] POST Routes
- [ ] Route Parameters
- [ ] Query Parameters

Example

```cpp
app.get("/", home);

app.get("/about", about);

app.post("/login", login);
```

---

## 🚧 Phase 3 — Middleware

- [ ] Middleware Pipeline
- [ ] Logging
- [ ] Authentication
- [ ] Error Handling

---

## 🚧 Phase 4 — Static Files

- [ ] HTML
- [ ] CSS
- [ ] JavaScript
- [ ] Images

---

## 🚧 Phase 5 — JSON

- [ ] JSON Responses
- [ ] JSON Parsing
- [ ] REST APIs

---

## 🚧 Phase 6 — Performance

- [ ] Thread Pool
- [ ] Keep-Alive Connections
- [ ] Connection Manager
- [ ] HTTP/1.1 Improvements

---

# 💡 Design Principles

TinyWeb++ follows several software engineering principles.

- Single Responsibility Principle
- Separation of Concerns
- Object-Oriented Design
- Readable Modern C++
- Educational First

Each class is responsible for exactly one part of the HTTP lifecycle.

---

# 📚 Learning Objectives

This project is designed to help understand

- TCP/IP Networking
- Socket Programming
- HTTP Protocol
- Request Parsing
- Response Generation
- Backend Framework Architecture
- Modern C++
- Software Design Principles

---

# 📈 Project Status

| Component | Status |
|-----------|--------|
| TCP Server | ✅ Complete |
| Request Parser | ✅ Complete |
| Response Generator | ✅ Complete |
| Router | 🚧 In Progress |
| Middleware | ⏳ Planned |
| Static Files | ⏳ Planned |
| JSON | ⏳ Planned |
| Thread Pool | ⏳ Planned |

---

# 🤝 Contributing

Contributions, suggestions, and discussions are welcome.

Feel free to open an issue or submit a pull request.

---

# 📜 License

This project is licensed under the MIT License.

---

# ⭐ Acknowledgements

TinyWeb++ is built from scratch as an educational project to explore the inner workings of modern web frameworks and gain a deeper understanding of backend development.