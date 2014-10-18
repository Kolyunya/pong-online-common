#include <Message/Message/HandshakeResponse/HandshakeResponse.hpp>

HandshakeResponse::HandshakeResponse ( const QHostAddress& address , quint16 port ) :
    HandshakeRequest(address,port)
{

}

HandshakeResponse::HandshakeResponse ( const QByteArray& message ) :
    HandshakeRequest(message)
{

}

MessageTransport HandshakeResponse::getTransport ( void ) const
{
    return MessageTransport::UDP;
}
