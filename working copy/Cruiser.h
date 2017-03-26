#ifndef CRUISER_H_INCLUDED
#define CRUISER_H_INCLUDED

#include "Constantes.h"
#include "Boat.h"

class Cruiser: public Boat
{
private:


public:
    //Constructor and destructor
    Cruiser();
    Cruiser(int pos_i, int pos_j, int dir, int hit_count, int length);
    ~Cruiser();

};

#endif // CRUISER_H_INCLUDED
