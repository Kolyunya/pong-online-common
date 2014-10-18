#include <SpriteModel/SpriteModel.hpp>

SpriteModel::SpriteModel ( qreal width , qreal height )
{
    this->setRectangle(width,height);
}

QRectF SpriteModel::getRectangle ( void ) const
{
    return this->rectangle;
}

QPointF SpriteModel::getPosition( void ) const
{
    return this->rectangle.center();
}

qreal SpriteModel::getPositionX( void ) const
{
    return this->getPosition().x();
}

qreal SpriteModel::getPositionY( void ) const
{
    return this->getPosition().y();
}

void SpriteModel::setRectangle( QRectF rectangle )
{
    this->rectangle = rectangle;
}

void SpriteModel::setRectangle(qreal width, qreal height)
{
    QRectF rectangle(0,0,width,height);
    this->setRectangle(rectangle);
}

void SpriteModel::setPosition ( QPointF position )
{
    this->rectangle.moveCenter(position);
}

void SpriteModel::setPosition ( qreal x , qreal y )
{
    QPointF position(x,y);
    this->setPosition(position);
}

void SpriteModel::setPositionX( qreal position )
{
    QPointF positionNew(position,this->getPositionY());
    this->setPosition(positionNew);
}

void SpriteModel::setPositionY( qreal position )
{
    QPointF positionNew(this->getPositionX(),position);
    this->setPosition(positionNew);
}

const QPointF& SpriteModel::getAbsoluteSpeed ( void ) const
{
    return this->absoluteSpeed;
}

const QPointF &SpriteModel::getMomentumSpeed() const
{
    return this->momentumSpeed;
}

void SpriteModel::setSpeedX( qreal speed )
{
    this->absoluteSpeed.setX(speed);
}

void SpriteModel::setSpeedY( qreal speed )
{
    this->absoluteSpeed.setY(speed);
}

void SpriteModel::addSpeedX ( qreal speed )
{
    qreal speedCurrent = this->absoluteSpeed.x();
    qreal speedNew = speedCurrent + speed;
    this->setSpeedX(speedNew);
}

void SpriteModel::addSpeedY ( qreal speed )
{
    qreal speedCurrent = this->absoluteSpeed.y();
    qreal speedNew = speedCurrent + speed;
    this->setSpeedY(speedNew);
}

void SpriteModel::multiplySpeedX( qreal speed )
{
    qreal speedCurrent = this->absoluteSpeed.x();
    qreal speedNew = speedCurrent * speed;
    this->setSpeedX(speedNew);
}

void SpriteModel::multiplySpeedY( qreal speed )
{
    qreal speedCurrent = this->absoluteSpeed.y();
    qreal speedNew = speedCurrent * speed;
    this->setSpeedY(speedNew);
}

void SpriteModel::invertSpeedX ( void )
{
    qreal speedCurrent = this->absoluteSpeed.x();
    qreal speedNew = speedCurrent * -1;
    this->setSpeedX(speedNew);
}

void SpriteModel::invertSpeedY ( void )
{
    qreal speedCurrent = this->absoluteSpeed.y();
    qreal speedNew = speedCurrent * -1;
    this->setSpeedY(speedNew);
}

void SpriteModel::stop ( void )
{
    this->setSpeedX(0);
    this->setSpeedY(0);
}

void SpriteModel::move( void )
{

    // Calculate sprite's momentum speed
    this->calculateMomentumSpeed();

    // Move the sprite by it's momentum speed
    this->rectangle.translate
    (
        this->momentumSpeed.x(),
        this->momentumSpeed.y()
    );

    // Update the last move time
    this->lastMoveTime = QTime::currentTime();

}

void SpriteModel::reset ( void )
{
    this->lastMoveTime = QTime::currentTime();
}

void SpriteModel::calculateMomentumSpeed ( void )
{

    // This is the first move
    if ( this->lastMoveTime.isNull() )
    {

        // The momentum speed is zero
        this->momentumSpeed.setX(0);
        this->momentumSpeed.setY(0);

    }

    // This is not the first move
    else
    {

        // Calculate the time span since the last move
        int lastMoveTimeSpan = this->lastMoveTime.msecsTo(QTime::currentTime());

        // Divide the absolute speed by the time passed since the last move
        this->momentumSpeed.setX ( this->absoluteSpeed.x() * lastMoveTimeSpan / 1000 );
        this->momentumSpeed.setY ( this->absoluteSpeed.y() * lastMoveTimeSpan / 1000 );

    }

}

