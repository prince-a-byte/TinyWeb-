#pragma once
#include <string>

struct HttpStatus
{
    int code;
    std::string message;
};

namespace Status
{
    inline const HttpStatus OK{200,"OK"};
    inline const HttpStatus CREATED{201,"Created"};
    inline const HttpStatus BAD_REQUEST{400,"Bad Request"};
    inline const HttpStatus NOT_FOUND{404,"Not Found"};
    inline const HttpStatus INTERNAL_SERVER_ERROR{500,"Internal Server Error"};
}
