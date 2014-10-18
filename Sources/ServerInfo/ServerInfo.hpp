#ifndef SERVERINFO_HPP
#define SERVERINFO_HPP

#include <QHostAddress>

class ServerInfo
{
    public:
        static const QHostAddress address;
        static const quint16 port;
};

#endif // SERVERINFO_HPP
