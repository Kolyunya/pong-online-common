#include <Message/Message/GameStarted/GameStarted.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

GameStarted::GameStarted ( void )
{
    this->initializeData();
}

GameStarted::GameStarted ( const QByteArray& message )
{
    this->initializeHeader();
    this->getBody(message);
}

void GameStarted::initializeHeader ( void )
{
    this->header = MessageHeader::GameStartedHeader;
}
