#include <Message/Message/HandshakeAck/HandshakeAck.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

HandshakeAck::HandshakeAck ( void )
{
    this->initializeData();
}

HandshakeAck::HandshakeAck ( QByteArray message )
{
    this->initializeHeader();
    this->getBody(message);
}

MessageTransport HandshakeAck::getTransport ( void ) const
{
    return MessageTransport::UDP;
}

void HandshakeAck::initializeHeader ( void )
{
    this->header = MessageHeader::HandshakeAckHeader;
}
