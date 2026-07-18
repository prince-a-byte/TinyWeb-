#include "server.h"

int main()
{
    Server app(8000);

    app.start();

    return 0;
}