#ifndef GAMEBASE_HPP
#define GAMEBASE_HPP

#include <QObject>
#include <Game/GameScore/GameScore.hpp>
#include <FieldModel/FieldModel.hpp>

class GameBase :
    public QObject
{
    Q_OBJECT
    public:
        explicit GameBase ( void );
        virtual ~GameBase ( void ) = default;
        FieldModel* getModelPtr ( void );
        GameScore getScore ( void );
    protected:
        FieldModel field;
        GameScore score;
    private:
        void initializeField ( void );
        void initializeScore ( void );
    signals:
        void fieldRedrawn ( void );
        void scoreChanged ( void );
        void scoreReachedLimit ( void );
};

#endif // GAMEBASE_HPP
