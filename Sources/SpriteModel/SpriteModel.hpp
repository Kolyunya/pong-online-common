#ifndef SPRITEMODEL_HPP
#define SPRITEMODEL_HPP

#include <QPointF>
#include <QRectF>
#include <QTime>

class SpriteModel
{
    public:
        explicit SpriteModel ( void ) = default;
        explicit SpriteModel ( qreal width , qreal height );
        QRectF getRectangle ( void ) const;
        QPointF getPosition ( void ) const;
        qreal getPositionX ( void ) const;
        qreal getPositionY ( void ) const;
        void setRectangle ( QRectF rectangle );
        void setRectangle ( qreal width , qreal height );
        void setPosition ( QPointF position );
        void setPosition ( qreal x , qreal y );
        void setPositionX ( qreal position );
        void setPositionY ( qreal position );
        const QPointF& getAbsoluteSpeed ( void ) const;
        const QPointF& getMomentumSpeed ( void ) const;
        void setSpeedX ( qreal speed );
        void setSpeedY ( qreal speed );
        void addSpeedX ( qreal speed );
        void addSpeedY ( qreal speed );
        void multiplySpeedX ( qreal speed );
        void multiplySpeedY ( qreal speed );
        void invertSpeedX ( void );
        void invertSpeedY ( void );
        void stop ( void );
        void move ( void );
        void reset ( void );
    private:
        void calculateMomentumSpeed ( void );
        QRectF rectangle;
        QPointF absoluteSpeed;
        QPointF momentumSpeed;
        QTime lastMoveTime;
};

#endif // SPRITEMODEL_HPP
