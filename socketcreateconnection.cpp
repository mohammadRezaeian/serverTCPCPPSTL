#include "socketcreateconnection.h"

socketCreateConnection::socketCreateConnection()
{

}

void socketCreateConnection::createConnection()
{
    m_socketDecriptor = socket(AF_INET , SOCK_STREAM , 0);
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

    m_socketAccept = accept(m_socketDecriptor , (struct sockaddr*)&m_server , (socklen_t*) &m_serverSize);
    if(m_socketAccept < 0)
    {
        cout << "cant accept\n";
    }

    read(m_socketAccept , m_readValue , sizeof(m_readValue));
    string _valueToString = m_readValue;
    if(!_valueToString.empty())
    {
        while(true)
        {
            usleep(SETTIMER);
            m_generator.setStatus((_valueToString) == "start" ? true : false);
            string _value =  m_generator.generateNumber();
            sendData(_value);
        }
    }
}

void socketCreateConnection::sendData(string _value)
{
    const char *cstr = _value.c_str();
    int resp = send(m_socketAccept,cstr, sizeof(cstr), 0);
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
