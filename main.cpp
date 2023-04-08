#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>
#include "socketcreateconnection.h"


using namespace std;

int main(int argc, char *argv[])
{
    socketCreateConnection _socket;
    _socket.createConnection();
    return 0;
}
