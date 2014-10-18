#ifndef HANDSHAKEREQUEST_HPP
#define HANDSHAKEREQUEST_HPP

#include <QHostAddress>
#include <Message/Message/Message/Message.hpp>

class HandshakeRequest :
    public Message
{
    public:
        explicit HandshakeRequest ( const QHostAddress& address , quint16 port );
        explicit HandshakeRequest ( const QByteArray& message );
        virtual ~HandshakeRequest ( void ) = default;
        virtual MessageTransport getTransport ( void ) const override;
        QHostAddress getAddress ( void ) const;
        quint16 getPort ( void ) const;
    private:
        void initializeHeader() override;
        QHostAddress address;
        quint16 port;
};

#endif // HANDSHAKEREQUEST_HPP
