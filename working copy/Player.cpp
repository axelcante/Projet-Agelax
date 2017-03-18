#include "Player.h"

//Constructeur par défaut
Player::Player() {}

//Constructeur surchargé
Player::Player(int playerNumber, bool isLost)
{
    m_isLost = isLost;
    m_player_number = playerNumber;
}

//Destructeur
Player::~Player() {}

//Getters
int Player::getPlayer_number()const
{
    return m_player_number;
}
bool Player::getIsLost()const
{
    return m_isLost;
}

//Setters
void Player::setPlayerNumber(int playerNumber)
{
    m_player_number = playerNumber;
}
void Player::setIsLost(bool isLost)
{
    m_isLost = isLost;
}
