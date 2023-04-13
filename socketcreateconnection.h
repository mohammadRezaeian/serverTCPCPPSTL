#ifndef SOCKETCREATECONNECTION_H
#define SOCKETCREATECONNECTION_H

#include "generator.h"

#include <iostream>
#include <string>
#include <cstring>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <algorithm>

#define PORTNUMBER        1234
#define ADDRESSCONNECTION "127.0.0.1"
#define SETTIMER          6000      //microsenod to milisecons it's  6
#define MAXIMUMCLIENT     1

class socketCreateConnection
{
public:
    socketCreateConnection();
    ~socketCreateConnection();
    void createConnection();
    void readFunction();
    void sendData(double _value);

private:
    int       m_socketDecriptor,
              m_socketAccept,
              m_valueRead;
    struct    sockaddr_in m_server;
    int       m_serverSize = sizeof(m_server);
    int       m_opt{1};
//    char      m_readValue[1024] ={0};
    bool m_status;
    Generator m_generator;
    bool      m_startCheckLoop = true;
    bool      m_startCheckSend = false;
};

#endif // SOCKETCREATECONNECTION_H
