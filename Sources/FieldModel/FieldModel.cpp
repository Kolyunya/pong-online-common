#include <FieldModel/FieldModel.hpp>
#include <Message/Message/FieldData/FieldData.hpp>

qreal FieldModel::width = 320;

qreal FieldModel::height = 480;

qreal FieldModel::playerWidth = 100;

qreal FieldModel::playerHeight = 20;

qreal FieldModel::playerSpeed = 300;

qreal FieldModel::ballWidth = 20;

qreal FieldModel::ballHeight = 20;

qreal FieldModel::ballSpeedX = 200;

qreal FieldModel::ballSpeedY = 200;

qreal FieldModel::padding = 5;

qreal FieldModel::platformCohesion = 0.2;

FieldModel::FieldModel ( void ) :
    isActive(false)
{
    this->configureRectangle();
    this->configurePlayer();
    this->configureEnemy();
    this->configureBall();
}

QPointF FieldModel::getCenter ( void ) const
{
    return this->rectangle.center();
}

const SpriteModel& FieldModel::getPlayer ( int playerId ) const
{
    return this->players.at(playerId);
}

const SpriteModel& FieldModel::getBall() const
{
    return this->ball;
}

QPointF FieldModel::getPlayerPosition ( int playerId ) const
{
    return this->players.at(playerId).getRectangle().center();
}

QPointF FieldModel::getBallPosition ( void ) const
{
    return this->ball.getRectangle().center();
}

void FieldModel::setPlayerMoveDirection ( int playerId , MoveDirection moveDirection )
{

    // For the first player the "left" and "right" move directions mathc
    // the actual "left" and "right" of the scene. For the second player
    // they are switched.

    qreal speed;

    switch ( moveDirection )
    {

        case MoveDirection::Left :
        {
            speed = playerId ? FieldModel::playerSpeed : - FieldModel::playerSpeed;
            break;
        }

        case MoveDirection::Right :
        {
            speed = playerId ? - FieldModel::playerSpeed : FieldModel::playerSpeed;
            break;
        }

        default :
        {
            speed = 0;
            break;
        }

    }

    this->players.at(playerId).setSpeedX(speed);

}

void FieldModel::setPlayerPosition ( int playerId , QPointF position )
{
    this->players.at(playerId).setPosition(position);
}

void FieldModel::setBallPosition ( QPointF position )
{
    this->ball.setPosition(position);
}

void FieldModel::resetBall ( void )
{

    // Configure ball position
    this->ball.setPosition(this->getCenter());

    // Configure ball speed
    this->ball.setSpeedX(FieldModel::ballSpeedX);
    this->ball.setSpeedY(FieldModel::ballSpeedY);

    // Reset ball internal status
    this->ball.reset();

    this->isActive = true;

}

void FieldModel::configureRectangle ( void )
{
    this->rectangle.setWidth(FieldModel::width);
    this->rectangle.setHeight(FieldModel::height);
}

void FieldModel::configurePlayer ( void )
{

    // Configure player's dimensions
    qreal playerWidth = FieldModel::playerWidth;
    qreal playerHeight = FieldModel::playerHeight;
    this->players.at(0).setRectangle(playerWidth,playerHeight);

    // "Player" is placed on the bottom of the scene
    qreal playerX = this->rectangle.width() / 2;
    qreal playerY = this->rectangle.height() - playerHeight;
    this->players.at(0).setPosition(playerX,playerY);

}

void FieldModel::configureEnemy ( void )
{

    // Configure enemy's dimensions
    qreal enemyWidth = FieldModel::playerWidth;
    qreal enemyHeight = FieldModel::playerHeight;
    this->players.at(1).setRectangle(enemyWidth,enemyHeight);

    // "Enemy" is placed on the top of the scene
    qreal enemyX = this->rectangle.width() / 2;
    qreal enemyY = enemyHeight;
    this->players.at(1).setPosition(enemyX,enemyY);

}

void FieldModel::configureBall ( void )
{

    // Configure ball dimensions
    this->ball.setRectangle(FieldModel::ballWidth,FieldModel::ballHeight);

    // Reset ball position
    this->resetBall();

}

void FieldModel::processCollisions ( void )
{
    this->checkPlatformSceneCollisions(this->players.at(0));
    this->checkPlatformSceneCollisions(this->players.at(1));
    this->checkBallPlatformCollisions();
    if ( this->isActive )
    {
        this->checkBallSceneCollisitions();
    }
}

void FieldModel::checkPlatformSceneCollisions ( SpriteModel& player )
{

    // Left wall collision
    if ( player.getRectangle().left() <= FieldModel::padding )
    {
        qreal positionX = player.getRectangle().width() / 2 + FieldModel::padding;
        player.setPositionX(positionX);
        player.stop();
    }

    // Right wall collision
    else if ( player.getRectangle().right() >= this->rectangle.width() - FieldModel::padding )
    {
        qreal positionX = this->rectangle.width() - player.getRectangle().width() / 2 - FieldModel::padding;
        player.setPositionX(positionX);
        player.stop();
    }

}

void FieldModel::checkBallSceneCollisitions ( void )
{

    // Left wall collision
    if ( this->ball.getRectangle().left() <= 0 )
    {
        qreal ballX = this->ball.getRectangle().width() / 2;
        this->ball.setPositionX(ballX);
        this->ball.invertSpeedX();
    }

    // Right wall collision
    if ( this->ball.getRectangle().right() >= this->rectangle.width() )
    {
        qreal ballX = this->rectangle.width() - this->ball.getRectangle().width() / 2;
        this->ball.setPositionX(ballX);
        this->ball.invertSpeedX();
    }

    // Bottom wall collision
    if ( this->ball.getRectangle().top() > this->rectangle.height() + this->ball.getRectangle().height() )
    {
        this->isActive = false;
        emit this->playerScored(1);
    }

    // Top wall collision
    if ( this->ball.getRectangle().bottom() < - this->ball.getRectangle().height() )
    {
        this->isActive = false;
        emit this->playerScored(0);
    }

}

void FieldModel::checkBallPlatformCollisions ( void )
{

    const SpriteModel& player = this->getPlayer(0);
    const SpriteModel& enemy = this->getPlayer(1);
    const SpriteModel& ball = this->getBall();
    QRectF playerRectangle = player.getRectangle();
    QRectF enemyRectangle = enemy.getRectangle();
    QRectF ballRectangle = ball.getRectangle();

    // Player
    if
    (
        ballRectangle.bottom() >= playerRectangle.top()
            &&
        ballRectangle.top() <= playerRectangle.top()
            &&
        ballRectangle.left() >= playerRectangle.left()
            &&
        ballRectangle.right() <= playerRectangle.right()
    )
    {
        qreal ballY = playerRectangle.top() - playerRectangle.height() / 2;
        this->ball.setPositionY(ballY);
        this->ball.invertSpeedY();
        qreal ballDeltaX = player.getAbsoluteSpeed().x() * FieldModel::platformCohesion;
        this->ball.addSpeedX(ballDeltaX);
    }

    // Enemy
    if
    (
        ballRectangle.top() <= enemyRectangle.bottom()
            &&
        ballRectangle.bottom() >= enemyRectangle.top()
            &&
        ballRectangle.left() >= enemyRectangle.left()
            &&
        ballRectangle.right() <= enemyRectangle.right()
    )
    {
        qreal ballY = enemyRectangle.bottom() + playerRectangle.height() / 2;
        this->ball.setPositionY(ballY);
        this->ball.invertSpeedY();
        qreal ballDeltaX = enemy.getAbsoluteSpeed().x() * FieldModel::platformCohesion;
        this->ball.addSpeedX(ballDeltaX);
    }

}

void FieldModel::update ( void )
{
    this->players.at(0).move();
    this->players.at(1).move();
    this->ball.move();
    this->processCollisions();
    emit this->updated();
}

void FieldModel::update ( FieldData* fieldData )
{
    this->setPlayerPosition(0,fieldData->getPlayer());
    this->setPlayerPosition(1,fieldData->getEnemy());
    this->setBallPosition(fieldData->getBall());
    emit this->updated();
}

