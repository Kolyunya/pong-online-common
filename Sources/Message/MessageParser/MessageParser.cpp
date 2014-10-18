#include <QByteArray>
#include <Message/MessageParser/MessageParser.hpp>
#include <Message/Message/StartGame/StartGame.hpp>
#include <Message/Message/GameStarted/GameStarted.hpp>
#include <Message/Message/GameEnded/GameEnded.hpp>
#include <Message/Message/Move/Move.hpp>
#include <Message/Message/FieldData/FieldData.hpp>
#include <Message/Message/ScoreData/ScoreData.hpp>
#include <Message/MessageTransport/MessageTransport.hpp>

Message* MessageParser::parse ( const QByteArray& message , MessageTransport transport )
{

    Message* messagePtr = nullptr;

    try
    {
        messagePtr = new StartGame(message);
    }
    catch ( ... ) { }

    try
    {
        messagePtr = new GameStarted(message);
    }
    catch ( ... ) { }

    try
    {
        messagePtr = new GameEnded(message);
    }
    catch ( ... ) { }

    try
    {
        messagePtr = new Move(message);
    }
    catch ( ... ) { }

    try
    {
        messagePtr = new FieldData(message);
    }
    catch ( ... ) { }

    try
    {
        messagePtr = new ScoreData(message);
    }
    catch ( ... ) { }

    if ( messagePtr == nullptr )
    {

        return nullptr;

    }

    MessageTransport messageTransport = messagePtr->getTransport();

    if ( messageTransport == transport )
    {

        return messagePtr;

    }

    return nullptr;

}
