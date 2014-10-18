#include <Message/Message/GameEnded/GameEnded.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

GameEnded::GameEnded ( void )
{
    this->initializeData();
}

GameEnded::GameEnded ( const QByteArray& message )
{
    this->initializeHeader();
    this->getBody(message);
}

void GameEnded::initializeHeader ( void )
{
    this->header = MessageHeader::GameEndedHeader;
}
