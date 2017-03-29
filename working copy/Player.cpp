#include "Player.h"
#include <iostream>

//// Enum pour les id
//enum string_code {
//    B1,
//    C1,
//    C2,
//    D1,
//    D2,
//    D3,
//    S1,
//    S2,
//    S3,
//    S4
//};

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
//Sets the positions for the boats
void Player::initializeBoats()
{

    //Instanciation of the boats with all values at 0 exept length
    Battleship B1= Battleship(0, 0, 0, 0, BATTLESHIP_LENGTH, "B1");
    Cruiser C1= Cruiser(0, 0, 0, 0, CRUISER_LENGTH, "C1");
    Cruiser C2= Cruiser(0, 0, 0, 0, CRUISER_LENGTH, "C2");
    Destroyer D1= Destroyer(0, 0, 0, 0, DESTROYER_LENGTH, "D1");
    Destroyer D2= Destroyer(0, 0, 0, 0, DESTROYER_LENGTH, "D2");
    Destroyer D3= Destroyer(0, 0, 0, 0, DESTROYER_LENGTH, "D3");
    Submarine S1= Submarine(0, 0, 0, 0, SUBMARINE_LENGTH, "S1");
    Submarine S2= Submarine(0, 0, 0, 0, SUBMARINE_LENGTH, "S2");
    Submarine S3= Submarine(0, 0, 0, 0, SUBMARINE_LENGTH, "S3");
    Submarine S4= Submarine(0, 0, 0, 0, SUBMARINE_LENGTH, "S4");
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
    bool gud=false;
    int pos_i;
    int pos_j;
    int dir;
    while(!gud){
        //Generate new random values
        pos_i= rand()%NBCOLS;
        pos_j= rand()%NBLIGNES;
        dir= rand()%4+1;

        switch(dir)
        {
        case UP:
            if(pos_j-BATTLESHIP_LENGTH>=-1) gud=true; //Checking that the battleship does not go beyond the board's limits
            break;
        case RIGHT:
            if(pos_i+BATTLESHIP_LENGTH<=NBCOLS) gud=true;
            break;
        case DOWN:
            if(pos_j+BATTLESHIP_LENGTH<=NBLIGNES) gud=true;
            break;
        case LEFT:
            if(pos_i-BATTLESHIP_LENGTH>=-1) gud=true;
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
        gud=false;
        while(!gud){
            gud= true;
            //We generate new random values
            pos_i =(rand()%NBCOLS);
            pos_j =(rand()%NBLIGNES);
            dir =(rand()%4+1);

            switch(dir)
            {
               case UP:
                if(pos_j-m_boats[i].get_length()<-1){   //Checking for conflicts with the board's limits
                    gud=false;
                    break;
                }
                for(int k=0; k<m_boats[i].get_length(); k++){   //for every case of the boat we want to place
                    for(int l=0; l<i; l++){                     //for every boat already placed on the board
                        if(m_boats[l].isOnThatSpot(pos_i, pos_j-k)){  //if the boat number l(L) of m_boats is on that spot
                            gud= false;
                            break;
                        }
                    }
                    if(!gud) break;
                }
                break;

            case RIGHT:
                if(pos_i+BATTLESHIP_LENGTH>NBCOLS){   //Checking for conflicts with the board's limits
                    gud=false;
                    break;
                }
                for(int k=0; k<m_boats[i].get_length(); k++){   //for every case of the boat we want to place
                    for(int l=0; l<i; l++){                     //for every boat already placed on the board
                        if(m_boats[l].isOnThatSpot(pos_i+k, pos_j)){  //if the boat number l(L) of m_boats is on that spot
                            gud= false;
                            break;
                        }
                    }
                    if(!gud) break;
                }
                break;

            case DOWN:
                if(pos_j+BATTLESHIP_LENGTH>NBLIGNES){   //Checking for conflicts with the board's limits
                    gud=false;
                    break;
                }
                for(int k=0; k<m_boats[i].get_length(); k++){   //for every case of the boat we want to place
                    for(int l=0; l<i; l++){                     //for every boat already placed on the board
                        if(m_boats[l].isOnThatSpot(pos_i, pos_j+k)){  //if the boat number l(L) of m_boats is on that spot
                            gud= false;
                            break;
                        }
                    }
                    if(!gud) break;
                }
                break;

            case LEFT:
                if(pos_i-BATTLESHIP_LENGTH<-1){   //Checking for conflicts with the board's limits
                    gud=false;
                    break;
                }
                for(int k=0; k<m_boats[i].get_length(); k++){   //for every case of the boat we want to place
                    for(int l=0; l<i; l++){                     //for every boat already placed on the board
                        if(m_boats[l].isOnThatSpot(pos_i-k, pos_j)){  //if the boat number l(L) of m_boats is on that spot
                            gud= false;
                            break;
                        }
                    }
                    if(!gud) break;
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

//Makes sure the specified move is possible
bool Player::moveBoat(std::string id, int dir)
{
    int b;
    if(id=="B1") b=0;
    if(id=="C1") b=1;
    if(id=="C2") b=2;
    if(id=="D1") b=3;
    if(id=="D2") b=4;
    if(id=="D3") b=5;
    if(id=="S1") b=6;
    if(id=="S2") b=7;
    if(id=="S3") b=8;
    if(id=="S4") b=9;

    bool gud= true;
    int pos_i= m_boats[b].get_pos_i();
    int pos_j= m_boats[b].get_pos_j();
    int length= m_boats[b].get_length();
    switch(dir)
    {
    case UP:
        if(m_boats[b].m_dir==UP){ //If the boat is facing the same direction as the movement
            if(pos_j-length<0){  //If the boat is going into a wall
                gud= false;
                break;
            }
            for(int i=0; i<(int)m_boats.size(); i++){  //For every boat
                if(m_boats[i].isOnThatSpot(pos_i, pos_j-length)){  //If another boat is on that spot
                    //gud=false;
                    break;
                }
            }
        }
        if(m_boats[b].m_dir==DOWN){ //If the boat is facing the opposing direction
            if(pos_j-1<0){  //If the boat is going into a wall
                gud= false;
                break;
            }
            for(int i=0; i<(int)m_boats.size(); i++){  //For every boat
                if(m_boats[i].isOnThatSpot(pos_i, pos_j-1)){  //If another boat is on that spot
                    //gud=false;
                    break;
                }
            }
        }
        if(m_boats[b].m_dir==RIGHT || m_boats[b].m_dir==LEFT){ //If the boat is perpendicular to the direction
            gud= false;
            break;
        }
        break;

    case RIGHT:
        if(m_boats[b].m_dir==RIGHT){ //If the boat is facing the same direction as the movement
            if(pos_i+length>NBCOLS){  //If the boat is going into a wall
                gud= false;
                break;
            }
            for(int i=0; i<(int)m_boats.size(); i++){  //For every boat
                if(m_boats[i].isOnThatSpot(pos_i+length, pos_j)){  //If another boat is on that spot
                    //gud=false;
                    break;
                }
            }
        }
        if(m_boats[b].m_dir==LEFT){ //If the boat is facing the opposing direction
            if(pos_i+1>NBCOLS){  //If the boat is going into a wall
                gud= false;
                break;
            }
            for(int i=0; i<(int)m_boats.size(); i++){  //For every boat
                if(m_boats[i].isOnThatSpot(pos_i+1, pos_j)){  //If another boat is on that spot
                    //gud=false;
                    break;
                }
            }
        }
        if(m_boats[b].m_dir==UP || m_boats[b].m_dir==DOWN){ //If the boat is perpendicular to the direction
            gud= false;
            break;
        }
        break;

    case DOWN:
        if(m_boats[b].m_dir==DOWN){ //If the boat is facing the same direction as the movement
            if(pos_j+length>NBLIGNES){  //If the boat is going into a wall
                gud= false;
                break;
            }
            for(int i=0; i<(int)m_boats.size(); i++){  //For every boat
                if(m_boats[i].isOnThatSpot(pos_i, pos_j+length)){  //If another boat is on that spot
                    //gud=false;
                    break;
                }
            }
        }
        if(m_boats[b].m_dir==UP){ //If the boat is facing the opposing direction
            if(pos_j+1>NBLIGNES){  //If the boat is going into a wall

                gud= false;
                break;
            }
            for(int i=0; i<(int)m_boats.size(); i++){  //For every boat
                if(m_boats[i].isOnThatSpot(pos_i, pos_j+1)){  //If another boat is on that spot
                    //gud=false;
                    break;
                }
            }
        }
        if(m_boats[b].m_dir==RIGHT || m_boats[b].m_dir==LEFT){ //If the boat is perpendicular to the direction
            gud= false;
            break;
        }
        break;

    case LEFT:
        if(m_boats[b].m_dir==LEFT){ //If the boat is facing the same direction as the movement
            if(pos_i-length<0){  //If the boat is going into a wall
                gud= false;
                break;
            }
            for(int i=0; i<(int)m_boats.size(); i++){  //For every boat
                if(m_boats[i].isOnThatSpot(pos_i-length, pos_j)){  //If another boat is on that spot
                    //gud=false;
                    break;
                }
            }
        }
        if(m_boats[b].m_dir==RIGHT){ //If the boat is facing the opposing direction
            if(pos_i-1<0){  //If the boat is going into a wall
                gud= false;
                break;
            }
            for(int i=0; i<(int)m_boats.size(); i++){  //For every boat
                if(m_boats[i].isOnThatSpot(pos_i-1, pos_j)){  //If another boat is on that spot
                    //gud=false;
                    break;
                }
            }
        }
        if(m_boats[b].m_dir==UP || m_boats[b].m_dir==DOWN){ //If the boat is perpendicular to the direction
            gud= false;
            break;
        }
        break;
    }

    if(gud){
        m_boats[b].move_boat(dir);
        return true;
    }

    return false;
}

