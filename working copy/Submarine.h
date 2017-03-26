#ifndef SUBMARINE_H_INCLUDED
#define SUBMARINE_H_INCLUDED

#include "Constantes.h"
#include "Boat.h"

class Submarine: public Boat
{
private:


public:
    //Constructor and destructor
    Submarine();
    Submarine(int pos_i, int pos_j, int dir, int hit_count, int length);
    ~Submarine();

};

#endif // SUBMARINE_H_INCLUDED
