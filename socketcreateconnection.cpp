#include "socketcreateconnection.h"

socketCreateConnection::socketCreateConnection() :
    m_status{false}
{

}

void socketCreateConnection::createConnection()
{
    m_socketDecriptor = socket(AF_INET , SOCK_STREAM , 0);
    //    fcntl(m_socketDecriptor, F_SETFL, O_NONBLOCK);

    if(m_socketDecriptor == -1)
    {
        cout << "could not create Socket\n";
    }

    if((setsockopt(m_socketDecriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &m_opt,sizeof(m_opt))) == -1) ;
    {
        cout << "setsockopt\n";
    }

    m_server.sin_family = AF_INET;
    m_server.sin_addr.s_addr = inet_addr(ADDRESSCONNECTION);
    m_server.sin_port = htons(PORTNUMBER);

    if((bind(m_socketDecriptor , (struct sockaddr*)&m_server , sizeof(m_server))) < 0)
    {
        cout << "bind done\n";
    }

    listen(m_socketDecriptor , MAXIMUMCLIENT);

    m_socketAccept = accept4(m_socketDecriptor , (struct sockaddr*)&m_server , (socklen_t*) &m_serverSize , SOCK_NONBLOCK);
    if(m_socketAccept < 0)
    {
        cout << "cant accept\n";
    }
    readFunction();
}
void socketCreateConnection::readFunction()
{
    char m_readValue[128] = {0};
    while(true)
    {
        read(m_socketAccept , m_readValue , sizeof(m_readValue));

        switch (m_readValue[0]) {
        case 'A':
            m_status = true;
            break;
        case 'B':
            m_status = false;
            break;
        default:
            break;
        }

        m_generator.setStatus(m_status);
        double _value =  m_generator.generateNumber();
        sendData(_value);

        usleep(SETTIMER);
    }

}
void socketCreateConnection::sendData(double _value)
{
    std::cout << "_value: " << _value;
    char _valueSend[sizeof(double)+2];
    _valueSend[0] = 72;
    _valueSend[1] = 105;

    memcpy(&_valueSend[2], &_value, sizeof(double));

    int resp = send(m_socketAccept, _valueSend, (sizeof(double)+2), 0);
    std::cout << "\nrep: " << resp;
    if ( resp == -1 && errno == EPIPE )
    {
        close(m_socketDecriptor);
    }
}

socketCreateConnection::~socketCreateConnection()
{
    if(m_socketDecriptor < 0)
    {
        close(m_socketDecriptor);
    }
}
