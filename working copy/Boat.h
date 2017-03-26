#ifndef BOAT_H_INCLUDED
#define BOAT_H_INCLUDED

#include "Constantes.h"
#include <vector>

///Boat class
class Boat
{
private:


public:
    //Variables
    int m_pos_i; //Horizontal position
    int m_pos_j; //Vertical position
    int m_dir;   //Direction the boat is facing
    int m_hit_count; //Number of times the boat was hit
    bool m_isPlaced;

    ///Transition avec boat
    int m_length; //The lenght of the boat
    std::vector<bool> m_hit_map;//Keeps track of where the boat is hit
    ///

    //Default constructor
    Boat();
    //Overloaded constructor
    Boat(int pos_i, int pos_j, int dir, int hit_count, int length);
    //Destructor
    ~Boat();

    //Setters
    void set_pos_i(int i);
    void set_pos_j(int j);
    void set_dir(int dir);
    void set_isPlaced(bool isPlaced);

    //Getters
    int get_pos_i();
    int get_pos_j();
    int get_dir();
    int get_length();

    //Add one to the hit counter
    void add_hit();
    //Moves the boat one case in the specified direction (if possible)
    bool move_boat(int dir);
    //Rotates the boat 90 degrees in the specified direction (if possible)
    bool rotate_boat(int dir);

    ///Transition avec boat
    //Is the boat hit by an enemy shell? If yes then set that spot as hit on the hit map
    bool isHit(int pos_i, int pos_j);
    //Is the boat on that specified spot? If yes return true (used for conflict testing)
    bool isOnThatSpot(int pos_i, int pos_j);
    //Is the boat dead?
    bool isDead();


};


#endif // BOAT_H_INCLUDED
