/*!
 * \file    main.cpp
 * \brief   
 *
 * \author  LiJunjie, holysoros@gmail.com
 * \version 0.00
 * \date    12-09-08 07:27:35
 */

#include <iostream>
#include <string>

#include "webServer.h"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    WebServer server;
    server.start();

    return 0;
}
