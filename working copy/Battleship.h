#ifndef BATTLESHIP_H_INCLUDED
#define BATTLESHIP_H_INCLUDED

#include "Constantes.h"
#include "Boat.h"
#include <vector>

class Battleship: public Boat
{
private:
    //The lenght of the boat
    int m_length= BATTLESHIP_LENGTH;
    //Keeps track of where the boat is hit
    std::vector<bool> m_hit_map;

public:
    //Constructor
    Battleship();
    //Is the boat hit by an enemy shell? If yes then set that spot as hit on the hit map
    bool isHit(int pos_i, int pos_j);
    //Is the boat on that specified spot? If yes return true (used for conflict testing)
    bool isOnThatSpot(int pos_i, int pos_j);
    //Is the boat dead?
    bool isDead();


};


#endif // BATTLESHIP_H_INCLUDED
