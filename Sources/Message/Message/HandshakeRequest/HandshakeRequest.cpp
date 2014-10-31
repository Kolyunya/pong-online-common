#include <QJsonDocument>
#include <QJsonObject>
#include <QException>
#include <Message/Message/HandshakeRequest/HandshakeRequest.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

HandshakeRequest::HandshakeRequest ( const QHostAddress& address , quint16 port )
{

    // Initialize message data with the header
    this->initializeData();

    // The rest of the message is a JSON object containing "address" and "port" properties
    QJsonObject handshakeJsonObject;
    handshakeJsonObject.insert("address",address.toString());
    handshakeJsonObject.insert("port",port);
    QJsonDocument handshakeJsonDocument(handshakeJsonObject);
    QByteArray handshakeJson(handshakeJsonDocument.toJson());
    this->data.append(handshakeJson);

}

HandshakeRequest::HandshakeRequest ( const QByteArray& message )
{

    // Initialize the message header
    this->initializeHeader();

    // Get the message body
    QByteArray messageBody = this->getBody(message);

    // Try to parse the message body
    QJsonDocument messageJsonDocument = QJsonDocument::fromJson(messageBody);
    QJsonObject messageJsonObject = messageJsonDocument.object();

    // Check if the message has required properties
    if
    (
        messageJsonObject.contains("address") == false
            ||
        messageJsonObject.contains("port") == false
    )
    {
        throw QException();
    }

    this->address = messageJsonObject.value("address").toString();
    this->port = messageJsonObject.value("port").toInt();

}

MessageTransport HandshakeRequest::getTransport ( void ) const
{
    return MessageTransport::TCP;
}

QHostAddress HandshakeRequest::getAddress ( void ) const
{
    return this->address;
}

quint16 HandshakeRequest::getPort ( void ) const
{
    return this->port;
}

void HandshakeRequest::initializeHeader ( void )
{
    this->header = MessageHeader::HandshakeHeader;
}
