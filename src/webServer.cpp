/*!
 * \file    webServer.cpp
 * \brief    
 * \author  LiJunjie, holysoros@gmail.com
 * \version 0.00
 * \date    12-09-08 07:36:07
 */

#include "webServer.h"

#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_Stream.h"

WebServer::WebServer()
    : _port(0)
{
}

int WebServer::start(uint16_t port)
{
    ACE_INET_Addr listen_addr;
    ACE_SOCK_Acceptor acceptor;
    ACE_SOCK_Stream peer;

    if (listen_addr.set(port) == -1) {
        return 1;
    }
    if (acceptor.open(listen_addr) == -1) {
        return 1;
    }

    for ( ; ; ) {
        if (acceptor.accept(peer) == -1) return 1;

        char buff[4096];
        int ret;
        while ((ret = peer.recv(buff, sizeof buff, 0)) > 0) {
            peer.send(buff, ret, 0);
        }
        if (ret <= 0) {
            peer.close();
        }
    }
}
