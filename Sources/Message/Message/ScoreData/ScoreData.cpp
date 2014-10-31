#include <QJsonDocument>
#include <QJsonObject>
#include <Message/Message/ScoreData/ScoreData.hpp>

ScoreData::ScoreData ( int playerScore , int enemyScore )
{

    // Initialize message header
    this->initializeData();

    // The rest of the message is a JSON object
    QJsonObject scoreJsonObject;
    scoreJsonObject.insert("player",playerScore);
    scoreJsonObject.insert("enemy",enemyScore);
    QJsonDocument scoreJsonDocument(scoreJsonObject);
    QByteArray scoreJson(scoreJsonDocument.toJson());
    this->data.append(scoreJson);

}

ScoreData::ScoreData ( const QByteArray& message )
{
    this->initializeHeader();
    QByteArray messageBody = this->getBody(message);
    QJsonDocument messageJsonDocument = QJsonDocument::fromJson(messageBody);
    QJsonObject messageJsonObject = messageJsonDocument.object();
    this->playerScore = messageJsonObject.value("player").toInt();
    this->enemyScore = messageJsonObject.value("enemy").toInt();
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
