#ifndef MOVE_HPP
#define MOVE_HPP

#include <Message/Message/Message/Message.hpp>
#include <MoveDirection/MoveDirection.hpp>

class Move :
    public Message
{
    public:
        Move ( MoveDirection direction );
        Move ( const QByteArray& message );
        MessageTransport getTransport ( void ) const override;
        MoveDirection getDirection ( void ) const;
    private:
        void initializeHeader ( void ) override;
        MoveDirection direction;
};

#endif // MOVE_HPP
