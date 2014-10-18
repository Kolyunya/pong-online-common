#include <Message/Message/ScoreData/ScoreData.hpp>

ScoreData::ScoreData ( int playerScore , int enemyScore )
{
    this->initializeData();
    this->data.append(playerScore);
    this->data.append(enemyScore);
}

ScoreData::ScoreData ( const QByteArray& message )
{
    this->initializeHeader();
    QByteArray messageBody = this->getBody(message);
    this->playerScore = messageBody.at(0);
    this->enemyScore = messageBody.at(1);
}

int ScoreData::getPlayerScore ( void ) const
{
    return this->playerScore;
}

int ScoreData::getEnemyScore ( void ) const
{
    return this->enemyScore;
}

void ScoreData::initializeHeader ( void )
{
    this->header = MessageHeader::ScoreDataHeader;
}
