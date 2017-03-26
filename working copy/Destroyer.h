#ifndef DESTROYER_H_INCLUDED
#define DESTROYER_H_INCLUDED

#include "Constantes.h"
#include "Boat.h"

class Destroyer: public Boat
{
private:


public:
    //Constructor and destructor
    Destroyer();
    Destroyer(int pos_i, int pos_j, int dir, int hit_count, int length);
    ~Destroyer();

};

#endif // DESTROYER_H_INCLUDED
