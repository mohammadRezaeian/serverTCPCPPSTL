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

#define PORTNUMBER        1234
#define ADDRESSCONNECTION "127.0.0.1"
#define SETTIMER          6000
#define MAXIMUMCLIENT     1

class socketCreateConnection
{
public:
    socketCreateConnection();
    ~socketCreateConnection();
    void createConnection();
    void sendData(string _value);
private:
    int       m_socketDecriptor,
              m_socketAccept,
              m_valueRead;
    struct    sockaddr_in m_server;
    int       m_serverSize = sizeof(m_server);
    int       m_opt{1};
    char      m_readValue[1024] ={0};
    Generator m_generator;
};

#endif // SOCKETCREATECONNECTION_H
