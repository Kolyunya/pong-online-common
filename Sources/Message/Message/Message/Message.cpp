#include <Message/Message/Message/Message.hpp>
#include <QException>

QByteArray Message::getData ( void ) const
{
    return this->data;
}

MessageHeader Message::getHeader ( void ) const
{
    return this->header;
}

MessageTransport Message::getTransport (  void ) const
{
    return MessageTransport::TCP;
}

QByteArray Message::getBody ( const QByteArray& message ) const
{
    this->validateHeader(message);
    QByteArray messageCopy(message);
    const QByteArray& messageBody = messageCopy.remove(0,1);
    return messageBody;
}

void Message::initializeData ( void )
{
    this->initializeHeader();
    this->data.append(this->header);
}

void Message::validateHeader ( const QByteArray& message ) const
{
    char messageHeader = message.at(0);
    bool headerIsInvalid = messageHeader != this->header;
    if ( headerIsInvalid == true )
    {
        throw QException();
    }
}
