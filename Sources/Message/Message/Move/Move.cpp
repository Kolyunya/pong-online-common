#include <QString>
#include <Message/Message/Move/Move.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

Move::Move ( MoveDirection direction ) :
    direction(direction)
{
    this->initializeData();
    this->initializeBody();
}

Move::Move ( const QByteArray& message )
{
    this->initializeHeader();
    QByteArray messageBody = this->getBody(message);
    QString directionString(messageBody);
    int directionNumber = directionString.toUInt();
    MoveDirection direction = static_cast<MoveDirection>(directionNumber);
    this->direction = direction;
}

MessageTransport Move::getTransport ( void ) const
{
    return MessageTransport::UDP;
}

MoveDirection Move::getDirection ( void ) const
{
    return this->direction;
}

void Move::initializeHeader ( void )
{
    this->header = MessageHeader::MoveHeader;
}

void Move::initializeBody ( void )
{
    QString directionString = QString::number(this->direction);
    this->data.append(directionString);
}
