#ifndef GAMESCORE_HPP
#define GAMESCORE_HPP

#include <array>
#include <QObject>

class ScoreData;

class GameScore :
    public QObject
{
    Q_OBJECT
    public:
        explicit GameScore ( void );
        quint8 getLimit ( void ) const;
        bool getLimitReached ( void ) const;
        void setLimit ( quint8 limit );
        quint8 getValue ( quint8 playerId ) const;
        void setValue ( quint8 playerId , quint8 value );
    private:
        void initializeScores ( void );
        void initializeLimit ( void );
        void checkLimitReached ( quint8 playerId );
        void checkLimitOverdrafted ( quint8 playerId );
        static void validatePlayerId ( quint8 playerId );
        std::array<quint8,2> scores;
        quint8 limit;
    public slots:
        void increment ( quint8 playerId );
        void set ( ScoreData* scoreDataPtr );
    signals:
        void changed ( void );
        void reachedLimit ( void );
};

#endif // GAMESCORE_HPP
