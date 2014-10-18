#include <Message/Message/Move/Move.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

Move::Move ( MoveDirection direction )
{
    this->initializeData();
    this->data.append(direction);
}

Move::Move ( const QByteArray& message )
{
    this->initializeHeader();
    QByteArray messageBody = this->getBody(message);
    this->direction = static_cast<MoveDirection>(messageBody.at(0));
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
