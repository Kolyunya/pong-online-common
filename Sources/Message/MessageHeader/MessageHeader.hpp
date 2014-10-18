#ifndef MESSAGEHEADER_HPP
#define MESSAGEHEADER_HPP

enum MessageHeader
{

    HandshakeHeader,

    HandshakeAckHeader,

    StartGameHeader,

    GameStartedHeader,

    GameEndedHeader,

    MoveHeader,

    FieldDataHeader,

    ScoreDataHeader,

    DelimiterHeader = 42

};

#endif // MESSAGEHEADER_HPP
