#ifndef WEBSERVER_H

#define WEBSERVER_H

#include <stdint.h>

class WebServer {
public:
    WebServer();

    int start(uint16_t port = 8888);

private:
    uint16_t _port;
};

#endif /* end of include guard: WEBSERVER_H */
