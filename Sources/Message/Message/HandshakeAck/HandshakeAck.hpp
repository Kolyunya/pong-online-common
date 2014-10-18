#ifndef HANDSHAKEACK_HPP
#define HANDSHAKEACK_HPP

#include <Message/Message/Message/Message.hpp>

class HandshakeAck :
    public Message
{
    public:
        explicit HandshakeAck ( void );
        explicit HandshakeAck ( QByteArray message );
        MessageTransport getTransport ( void ) const override;
    private:
        void initializeHeader ( void ) override;
};

#endif // HANDSHAKEACK_HPP
