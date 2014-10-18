#ifndef FIELDMODEL_HPP
#define FIELDMODEL_HPP

#include <array>
#include <QPointF>
#include <QRectF>
#include <SpriteModel/SpriteModel.hpp>
#include <MoveDirection/MoveDirection.hpp>

class FieldData;

class FieldModel :
    public QObject
{
    Q_OBJECT
    public:
        explicit FieldModel ( void );
        QPointF getCenter ( void ) const;
        const SpriteModel& getPlayer ( int playerId ) const;
        const SpriteModel& getBall ( void ) const;
        QPointF getPlayerPosition ( int playerId ) const;
        QPointF getBallPosition ( void ) const;
        void setPlayerMoveDirection ( int playerId , MoveDirection moveDirection );
        void setPlayerPosition ( int playerId , QPointF position );
        void setBallPosition ( QPointF position );
        void resetBall ( void );
    private:
        void configureRectangle ( void );
        void configurePlayer ( void );
        void configureEnemy ( void );
        void configureBall ( void );
        void processCollisions ( void );
        void checkPlatformSceneCollisions ( SpriteModel& player );
        void checkBallSceneCollisitions ( void );
        void checkBallPlatformCollisions ( void );
        std::array<SpriteModel,2> players;
        SpriteModel ball;
        QRectF rectangle;
        bool isActive;
        static qreal width;
        static qreal height;
        static qreal playerWidth;
        static qreal playerHeight;
        static qreal playerSpeed;
        static qreal ballWidth;
        static qreal ballHeight;
        static qreal ballSpeedX;
        static qreal ballSpeedY;
        static qreal padding;
        static qreal platformCohesion;
    public slots:
        void update ( void );
        void update ( FieldData* fieldData );
    signals:
        void updated ( void );
        void playerScored ( quint8 playerId );
};

#endif // FIELDMODEL_HPP
