#ifndef GAMEENDED_HPP
#define GAMEENDED_HPP

#include <Message/Message/Message/Message.hpp>

class GameEnded :
    public Message
{
    public:
        GameEnded ( void );
        GameEnded ( const QByteArray& message );
    private:
        void initializeHeader ( void ) override;
};

#endif // GAMEENDED_HPP
