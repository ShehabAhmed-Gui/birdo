#include "player.h"

Player::Player()
{}

Player::~Player()
{}

QString Player::currentVideoName() const
{
    return m_currentVideoName;
}

void Player::currentVideoName(const QString &newCurrentVideoName)
{
    if (m_currentVideoName == newCurrentVideoName)
        return;
    m_currentVideoName = newCurrentVideoName;
    emit currentVideoNameChanged();
}
