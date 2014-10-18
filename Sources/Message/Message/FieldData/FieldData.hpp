#ifndef FIELDDATA_HPP
#define FIELDDATA_HPP

#include <QPointF>
#include <QJsonArray>
#include <QJsonValue>
#include <Message/Message/Message/Message.hpp>

class FieldData :
    public Message
{
    public:
        explicit FieldData ( const QPointF& player , const QPointF& enemy , const QPointF& ball );
        explicit FieldData ( const QByteArray& message );
        virtual ~FieldData ( void ) = default;
        virtual MessageTransport getTransport ( void ) const override;
        QPointF getPlayer ( void ) const;
        QPointF getEnemy ( void ) const;
        QPointF getBall ( void ) const;
        quint64 getTimestamp ( void ) const;
    private:
        static QJsonArray serializePoint ( const QPointF& point );
        static QPointF deserializePoint ( const QJsonValue& pointJson );
        void initializeHeader() override;
        QPointF player;
        QPointF enemy;
        QPointF ball;
        quint64 timestamp;
};

#endif // FIELDDATA_HPP
