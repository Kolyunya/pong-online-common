#ifndef SCOREDATA_HPP
#define SCOREDATA_HPP

#include <Message/Message/Message/Message.hpp>

class ScoreData :
    public Message
{
    public:
        ScoreData ( int playerScore , int enemyScore );
        ScoreData ( const QByteArray& message );
        int getPlayerScore ( void ) const;
        int getEnemyScore ( void ) const;
    private:
        void initializeHeader ( void ) override;
        int playerScore;
        int enemyScore;
};

#endif // SCOREDATA_HPP
