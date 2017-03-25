#include "Player.h"

//Default constructor
Player::Player() {}

//Overloaded constructor
Player::Player(int playerNumber, bool isLost)
{
    m_isLost = isLost;
    m_player_number = playerNumber;
}

//Destructor
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
char Player::getShotsFired(int i, int j)const
{
    return m_shots_fired[i][j];
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
void Player::setShotsFired(int i, int j, char a)
{
    m_shots_fired[i][j] = a;
}
