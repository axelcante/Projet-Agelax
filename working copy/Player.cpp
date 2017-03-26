#include "Player.h"
#include <iostream>

//Default constructor
Player::Player() {}

//Overloaded constructor
Player::Player(int playerNumber, bool isLost)
{
    m_isLost = isLost;
    m_player_number = playerNumber;
    initializeBoats();
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

//Methods
void Player::initializeBoats()
{
    srand(time(NULL)); //Initialize random function

    //Instanciation of the boats with all values at 0 exept length
    Battleship B1= Battleship(0, 0, 0, 0, BATTLESHIP_LENGTH);
    Cruiser C1= Cruiser(0, 0, 0, 0, CRUISER_LENGTH);
    Cruiser C2= Cruiser(0, 0, 0, 0, CRUISER_LENGTH);
    Destroyer D1= Destroyer(0, 0, 0, 0, DESTROYER_LENGTH);
    Destroyer D2= Destroyer(0, 0, 0, 0, DESTROYER_LENGTH);
    Destroyer D3= Destroyer(0, 0, 0, 0, DESTROYER_LENGTH);
    Submarine S1= Submarine(0, 0, 0, 0, SUBMARINE_LENGTH);
    Submarine S2= Submarine(0, 0, 0, 0, SUBMARINE_LENGTH);
    Submarine S3= Submarine(0, 0, 0, 0, SUBMARINE_LENGTH);
    Submarine S4= Submarine(0, 0, 0, 0, SUBMARINE_LENGTH);
    //Pushing those boats in the m_boats vector
    m_boats.push_back(B1);
    m_boats.push_back(C1);
    m_boats.push_back(C2);
    m_boats.push_back(D1);
    m_boats.push_back(D2);
    m_boats.push_back(D3);
    m_boats.push_back(S1);
    m_boats.push_back(S2);
    m_boats.push_back(S3);
    m_boats.push_back(S4);

    //First, we place the battleship on the board. We only need to check for conflicts with the board's limits.
    bool pos_correct=false;
    int pos_i;
    int pos_j;
    int dir;
    while(!pos_correct){
        //Generating new random values
        pos_i= rand()%NBCOLS+1;
        pos_j= rand()%NBLIGNES+1;
        dir= rand()%4+1;

        switch(dir)
        {
        case UP:
            if(pos_j-BATTLESHIP_LENGTH>=-1) pos_correct=true; //Checking that the battleship does not go beyond the board's limits
            break;
        case RIGHT:
            if(pos_i+BATTLESHIP_LENGTH<=NBCOLS+1) pos_correct=true;
            break;
        case DOWN:
            if(pos_j+BATTLESHIP_LENGTH<=NBLIGNES+1) pos_correct=true;
            break;
        case LEFT:
            if(pos_i-BATTLESHIP_LENGTH<=-1) pos_correct=true;
            break;
        default:
            std::cout << std::endl << "error: randomized dir takes anormal values in initializeBoats().";
            break;
        }
    }
    //Once the variables are valid we assign them to the battleship
    m_boats[0].set_pos_i(pos_i);
    m_boats[0].set_pos_j(pos_j);
    m_boats[0].set_dir(dir);

    //We can now place every other boat on the board
    for(int i=1; i<(int)m_boats.size(); i++)
    {
        pos_correct=false;
        while(!pos_correct){
            pos_correct= true;
            //We generate new random values
            pos_i =(rand()%NBCOLS+1);
            pos_j =(rand()%NBLIGNES+1);
            dir =(rand()%4+1);

            switch(dir)
            {
               case UP:
                if(pos_j-m_boats[i].get_length()<-1){   //Checking for conflicts with the board's limits
                    pos_correct=false;
                    break;
                }
                for(int k=0; k<m_boats[i].get_length(); k++){   //for every case of the boat we want to place
                    for(int l=0; l<i; l++){                     //for every boat already placed on the board
                        if(m_boats[l].isOnThatSpot(pos_i, pos_j-k)){  //if the boat number l(L) of m_boats is on that spot
                            pos_correct= false;
                            break;
                        }
                    }
                    if(!pos_correct) break;
                }
                break;

            case RIGHT:
                if(pos_i+BATTLESHIP_LENGTH>NBCOLS+1){   //Checking for conflicts with the board's limits
                    pos_correct=false;
                    break;
                }
                for(int k=0; k<m_boats[i].get_length(); k++){   //for every case of the boat we want to place
                    for(int l=0; l<i; l++){                     //for every boat already placed on the board
                        if(m_boats[l].isOnThatSpot(pos_i+k, pos_j)){  //if the boat number l(L) of m_boats is on that spot
                            pos_correct= false;
                            break;
                        }
                    }
                    if(!pos_correct) break;
                }
                break;

            case DOWN:
                if(pos_j+BATTLESHIP_LENGTH>NBLIGNES+1){   //Checking for conflicts with the board's limits
                    pos_correct=false;
                    break;
                }
                for(int k=0; k<m_boats[i].get_length(); k++){   //for every case of the boat we want to place
                    for(int l=0; l<i; l++){                     //for every boat already placed on the board
                        if(m_boats[l].isOnThatSpot(pos_i, pos_j+k)){  //if the boat number l(L) of m_boats is on that spot
                            pos_correct= false;
                            break;
                        }
                    }
                    if(!pos_correct) break;
                }
                break;

            case LEFT:
                if(pos_i-BATTLESHIP_LENGTH>-1){   //Checking for conflicts with the board's limits
                    pos_correct=false;
                    break;
                }
                for(int k=0; k<m_boats[i].get_length(); k++){   //for every case of the boat we want to place
                    for(int l=0; l<i; l++){                     //for every boat already placed on the board
                        if(m_boats[l].isOnThatSpot(pos_i-k, pos_j)){  //if the boat number l(L) of m_boats is on that spot
                            pos_correct= false;
                            break;
                        }
                    }
                    if(!pos_correct) break;
                }
                break;

            default:
                std::cout << std::endl << "error: randomized dir takes anormal values in initializeBoats().";
                break;
            }
        }
    m_boats[i].set_pos_i(pos_i);
    m_boats[i].set_pos_j(pos_j);
    m_boats[i].set_dir(dir);
    }
}

