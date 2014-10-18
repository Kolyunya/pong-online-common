#include <Game/GameBase/GameBase.hpp>

GameBase::GameBase()
{
    this->initializeField();
    this->initializeScore();
}

FieldModel*GameBase::getModelPtr()
{
    return &this->field;
}

void GameBase::initializeField()
{

    QObject::connect
    (
        &this->field,
        SIGNAL(updated()),
        this,
        SIGNAL(fieldRedrawn())
    );

    QObject::connect
    (
        &this->field,
        SIGNAL(playerScored(quint8)),
        &this->score,
        SLOT(increment(quint8))
    );

}

void GameBase::initializeScore()
{

    QObject::connect
    (
        &this->score,
        SIGNAL(changed()),
        this,
        SIGNAL(scoreChanged())
    );

    QObject::connect
    (
        &this->score,
        SIGNAL(reachedLimit()),
        this,
        SIGNAL(scoreReachedLimit())
    );

}
