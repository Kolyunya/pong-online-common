#include <QJsonDocument>
#include <QJsonObject>
#include <QException>
#include <QDataStream>
#include <QDateTime>
#include <QVariant>
#include <Message/Message/FieldData/FieldData.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

FieldData::FieldData(const QPointF& player, const QPointF& enemy, const QPointF& ball)
{

    // Initialize message data with the header
    this->initializeData();

    // The rest of the message is a JSON object containing "player", "enemy" and "ball" properties
    QJsonObject fieldDataJsonObject;
    fieldDataJsonObject.insert("player",FieldData::serializePoint(player));
    fieldDataJsonObject.insert("enemy",FieldData::serializePoint(enemy));
    fieldDataJsonObject.insert("ball",FieldData::serializePoint(ball));
    fieldDataJsonObject.insert("timestamp",QDateTime::currentMSecsSinceEpoch());
    QJsonDocument fieldDataJsonDocument(fieldDataJsonObject);
    QByteArray fieldDataJson(fieldDataJsonDocument.toBinaryData());
    this->data.append(fieldDataJson);

}

FieldData::FieldData(const QByteArray& message)
{

    // Initialize the message header
    this->initializeHeader();

    // Get the message body
    QByteArray messageBody = this->getBody(message);

    // Try to parse the message body
    QJsonDocument messageJsonDocument = QJsonDocument::fromBinaryData(messageBody);
    QJsonObject messageJsonObject = messageJsonDocument.object();

    // Check if the message has required properties
    if
    (
        messageJsonObject.contains("player") == false
            ||
        messageJsonObject.contains("enemy") == false
            ||
        messageJsonObject.contains("ball") == false
            ||
        messageJsonObject.contains("timestamp") == false
    )
    {
        throw QException();
    }

    this->player = FieldData::deserializePoint(messageJsonObject.value("player"));
    this->enemy = FieldData::deserializePoint(messageJsonObject.value("enemy"));
    this->ball = FieldData::deserializePoint(messageJsonObject.value("ball"));
    this->timestamp = messageJsonObject.value("timestamp").toVariant().toDateTime().toMSecsSinceEpoch();

}

MessageTransport FieldData::getTransport() const
{
    return MessageTransport::UDP;
}

QPointF FieldData::getPlayer() const
{
    return this->player;
}

QPointF FieldData::getEnemy() const
{
    return this->enemy;
}

QPointF FieldData::getBall() const
{
    return this->ball;
}

quint64 FieldData::getTimestamp() const
{
    return this->timestamp;
}

QJsonArray FieldData::serializePoint(const QPointF& point)
{
    QJsonArray pointArray;
    pointArray.append(point.x());
    pointArray.append(point.y());
    return pointArray;
}

QPointF FieldData::deserializePoint ( const QJsonValue& pointJson )
{
    QPointF point;
    QJsonArray pointArray = pointJson.toArray();
    point.setX(pointArray[0].toDouble());
    point.setY(pointArray[1].toDouble());
    return point;
}

void FieldData::initializeHeader()
{
    this->header = MessageHeader::FieldDataHeader;
}
