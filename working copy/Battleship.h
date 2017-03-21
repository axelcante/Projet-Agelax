#ifndef BATTLESHIP_H_INCLUDED
#define BATTLESHIP_H_INCLUDED

#include "Constantes.h"
#include "Boat.h"

class Battleship: public Boat
{
private:
    //The lenght of the boat
    int m_length= BATTLESHIP_LENGTH;

public:
    //Is the boat hit by an enemy shell?
    bool isHit(int pos_i, int pos_j);


};


#endif // BATTLESHIP_H_INCLUDED
