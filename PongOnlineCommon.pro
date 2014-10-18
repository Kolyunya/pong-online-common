TEMPLATE = lib

TARGET = PongOnlineCommon

QT += \
    network \

QT -= \
    gui \

CONFIG += \
    staticlib \
    c++11 \

QMAKE_CXXFLAGS += \
    -Wall \
    -Wextra \
    -Werror \
    -pedantic \
    -pedantic-errors \

debug:DESTDIR = Build/Debug
release:DESTDIR = Build/Release
OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc
UI_DIR = $$DESTDIR/.ui

INCLUDEPATH += \
    Sources \

HEADERS += \
    Sources/Game/GameScore/GameScore.hpp \
    Sources/Message/Message/Message/Message.hpp \
    Sources/Message/Message/StartGame/StartGame.hpp \
    Sources/Message/Message/GameStarted/GameStarted.hpp \
    Sources/Message/Message/Delimiter/Delimiter.hpp \
    Sources/Message/MessageHeader/MessageHeader.hpp \
    Sources/ServerInfo/ServerInfo.hpp \
    Sources/Message/MessageParser/MessageParser.hpp \
    Sources/FieldModel/FieldModel.hpp \
    Sources/SpriteModel/SpriteModel.hpp \
    Sources/Message/Message/Move/Move.hpp \
    Sources/Message/MessageTransport/MessageTransport.hpp \
    Sources/MoveDirection/MoveDirection.hpp \
    Sources/Message/Message/HandshakeRequest/HandshakeRequest.hpp \
    Sources/Message/Message/HandshakeResponse/HandshakeResponse.hpp \
    Sources/Message/Message/HandshakeAck/HandshakeAck.hpp \
    Sources/Game/GameBase/GameBase.hpp \
    Sources/Message/Message/GameEnded/GameEnded.hpp \
    Sources/Message/Message/FieldData/FieldData.hpp \
    Sources/Message/Message/ScoreData/ScoreData.hpp \

SOURCES += \
    Sources/Game/GameScore/GameScore.cpp \
    Sources/Message/Message/Message/Message.cpp \
    Sources/Message/Message/StartGame/StartGame.cpp \
    Sources/Message/Message/GameStarted/GameStarted.cpp \
    Sources/Message/Message/Delimiter/Delimiter.cpp \
    Sources/ServerInfo/ServerInfo.cpp \
    Sources/Message/MessageParser/MessageParser.cpp \
    Sources/FieldModel/FieldModel.cpp \
    Sources/SpriteModel/SpriteModel.cpp \
    Sources/Message/Message/Move/Move.cpp \
    Sources/Message/Message/HandshakeRequest/HandshakeRequest.cpp \
    Sources/Message/Message/HandshakeResponse/HandshakeResponse.cpp \
    Sources/Message/Message/HandshakeAck/HandshakeAck.cpp \
    Sources/Game/GameBase/GameBase.cpp \
    Sources/Message/Message/GameEnded/GameEnded.cpp \
    Sources/Message/Message/FieldData/FieldData.cpp \
    Sources/Message/Message/ScoreData/ScoreData.cpp \

unix
{
    target.path = /usr/lib
    INSTALLS += target
}
