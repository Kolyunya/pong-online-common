#ifndef GAMESTARTED_HPP
#define GAMESTARTED_HPP

#include <Message/Message/Message/Message.hpp>

class GameStarted :
    public Message
{
    public:
        GameStarted ( void );
        GameStarted ( const QByteArray& message );
    private:
        void initializeHeader ( void ) override;
};

#endif // GAMESTARTED_HPP
