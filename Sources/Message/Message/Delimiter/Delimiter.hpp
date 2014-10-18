#ifndef DELIMITER_HPP
#define DELIMITER_HPP

#include <Message/Message/Message/Message.hpp>

class Delimiter :
    public Message
{
    public:
        Delimiter ( void );
    private:
        void initializeHeader ( void ) override;
};

#endif // DELIMITER_HPP
