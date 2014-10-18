#ifndef MESSAGEPARSER_HPP
#define MESSAGEPARSER_HPP

#include <Message/MessageTransport/MessageTransport.hpp>

class QByteArray;

class Message;

class MessageParser
{
    public:
        static Message* parse ( const QByteArray& message , MessageTransport transport );
};

#endif // MESSAGEPARSER_HPP
