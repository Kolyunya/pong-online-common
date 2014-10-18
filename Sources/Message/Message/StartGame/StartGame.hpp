#ifndef STARTGAME_HPP
#define STARTGAME_HPP

#include <Message/Message/Message/Message.hpp>

class StartGame:
    public Message
{
    public:
        StartGame ( void );
        StartGame ( const QByteArray& message );
    private:
        void initializeHeader ( void ) override;
};

#endif // STARTGAME_HPP
