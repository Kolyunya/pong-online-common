#include <QException>
#include <Game/GameScore/GameScore.hpp>
#include <Message/Message/ScoreData/ScoreData.hpp>

GameScore::GameScore ( void )
{
    this->initializeScores();
    this->initializeLimit();
}

quint8 GameScore::getLimit ( void ) const
{
    return this->limit;
}

bool GameScore::getLimitReached() const
{
    return
    (
        this->scores.at(0) == this->limit
            ||
        this->scores.at(1) == this->limit
    );
}

void GameScore::setLimit ( quint8 limit )
{
    this->limit = limit;
}

quint8 GameScore::getValue ( quint8 playerId ) const
{
    GameScore::validatePlayerId(playerId);
    return this->scores.at(playerId);
}

void GameScore::setValue ( quint8 playerId , quint8 value )
{

    GameScore::validatePlayerId(playerId);
    this->scores.at(playerId) = value;

    // Score change signal should be emitted before score limit reach signal
    // so that the score panel appear before "game end" panel
    emit this->changed();

    this->checkLimitOverdrafted(playerId);
    this->checkLimitReached(playerId);

}

void GameScore::initializeScores ( void )
{
    this->setValue(0,0);
    this->setValue(1,0);
}

void GameScore::initializeLimit()
{
    this->setLimit(10);
}

void GameScore::checkLimitReached ( quint8 playerId )
{
    if ( this->scores.at(playerId) == this->limit )
    {
        emit this->reachedLimit();
    }
}

void GameScore::checkLimitOverdrafted ( quint8 playerId )
{
    if ( this->scores.at(playerId) > this->limit )
    {
        this->scores.at(playerId) = this->limit;
    }
}

void GameScore::validatePlayerId ( quint8 playerId )
{
    if ( playerId > 1 )
    {
        throw QException();
    }
}

void GameScore::increment ( quint8 playerId )
{
    GameScore::validatePlayerId(playerId);
    quint8 scoreCurrent = this->scores.at(playerId);
    this->setValue(playerId,scoreCurrent+1);
}

void GameScore::set ( ScoreData* scoreDataPtr )
{
    int player = scoreDataPtr->getPlayerScore();
    int enemy = scoreDataPtr->getEnemyScore();
    this->setValue(0,player);
    this->setValue(1,enemy);
}
