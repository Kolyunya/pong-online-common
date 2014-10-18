#ifndef HANDSHAKERESPONSE_HPP
#define HANDSHAKERESPONSE_HPP

#include <Message/Message/HandshakeRequest/HandshakeRequest.hpp>

class HandshakeResponse :
    public HandshakeRequest
{
    public:
        explicit HandshakeResponse ( const QHostAddress& address , quint16 port );
        explicit HandshakeResponse ( const QByteArray& message );
        virtual MessageTransport getTransport ( void ) const override;
};

#endif // HANDSHAKERESPONSE_HPP
