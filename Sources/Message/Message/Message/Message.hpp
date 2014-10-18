#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QByteArray>
#include <Message/MessageHeader/MessageHeader.hpp>
#include <Message/MessageTransport/MessageTransport.hpp>

class Message
{
    public:
        Message ( void ) = default;
        virtual ~Message ( void ) = default;
        QByteArray getData ( void ) const;
        MessageHeader getHeader ( void ) const;
        virtual MessageTransport getTransport ( void ) const;
    protected:
        QByteArray getBody ( const QByteArray& message ) const;
        void initializeData ( void );
        virtual void initializeHeader ( void ) = 0;
        QByteArray data;
        MessageHeader header;
    private:
        void validateHeader ( const QByteArray& message ) const;
};

#endif // MESSAGE_HPP
