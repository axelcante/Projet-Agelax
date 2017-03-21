#ifndef BOAT_H_INCLUDED
#define BOAT_H_INCLUDED

#include "Constantes.h"

///Boat class
class Boat
{
private:


public:
    //Variables
    int m_pos_i; //Horizontal position
    int m_pos_j; //Vertical position
    int m_dir;   //Direction the boat is facing
    int m_hit_count;    //Number of times the boat was hit
    bool m_isDead;  //Is the boat dead?

    //Default constructor
    Boat();
    //Overloaded constructor
    Boat(int pos_i, int pos_j, int dir, int hit_count);
    //Destructor
    ~Boat();

    //Setters
    void set_pos_i(int i);
    void set_pos_j(int j);
    void set_dir(int dir);

    //Getters
    int get_pos_i();
    int get_pos_j();
    int get_dir();

    //Add one to the hit counter
    void add_hit();
    //Moves the boat one case in the specified direction (if possible)
    bool move_boat(int dir);
    //Rotates the boat 90 degrees in the specified direction (if possible)
    bool rotate_boat(int dir);

};


#endif // BOAT_H_INCLUDED
