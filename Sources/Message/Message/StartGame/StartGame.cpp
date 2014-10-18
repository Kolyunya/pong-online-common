#include <Message/Message/StartGame/StartGame.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

StartGame::StartGame ( void )
{
    this->initializeData();
}

StartGame::StartGame ( const QByteArray& message )
{
    this->initializeHeader();
    this->getBody(message);
}

void StartGame::initializeHeader ( void )
{
    this->header = MessageHeader::StartGameHeader;
}
