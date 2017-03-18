#ifndef BATTLESHIP_H_INCLUDED
#define BATTLESHIP_H_INCLUDED

class Battleship: public Boat
{
private:
    int length= 7; //remplacer 7 par un define BATTLESHIP_LENGTH 7 dans constants.h

public:
    //Is the boat hit by an enemy shell?
    bool isHit(int pos_i, int pos_j);

};


#endif // BATTLESHIP_H_INCLUDED
