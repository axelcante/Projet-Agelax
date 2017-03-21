#include "Boat.h"

//Default constructor
Boat::Boat(){}

//Overloaded constructor
Boat::Boat(int pos_i, int pos_j, int dir, int hit_count)
{
  m_pos_i = pos_i;
  m_pos_j = pos_j;
  m_dir = dir;
  m_hit_count = hit_count;
}

// Destructor
Boat::~Boat(){}

//Setters
void Boat::set_pos_i(int i) { m_pos_i = i; }
void Boat::set_pos_j(int j) { m_pos_j = j; }
void Boat::set_dir(int dir) { m_dir = dir; }

//Getters
int Boat::get_pos_i() { return m_pos_i; }
int Boat::get_pos_j() { return m_pos_j; }
int Boat::get_dir() { return m_dir; }

//Add one to the hit counter
void Boat::add_hit()
{
    m_hit_count++;
}

//Moves the boat one case in the specified direction (collision verification done in Game class)
//Makes sure the boat is correctly aligned
bool Boat::move_boat(int dir)
{
    //Switch case for each direction
    switch(dir)
    {
    case UP:
        if(m_dir==(UP && DOWN)) { m_pos_j--; return true; } //returns true is all went well
        else return false; //returns false if the boat is not corectly aligned
        break;
    case RIGHT:
        if(m_dir==(RIGHT && LEFT)) { m_pos_i++; return true; }
        else return false;
        break;
    case DOWN:
        if(m_dir==(UP && DOWN)) { m_pos_j++; return true; }
        else return false;
        break;
    case LEFT:
        if(m_dir==(RIGHT && LEFT)) { m_pos_i--; return true; }
        else return false;
        break;
    default:
        return false;
        break;
    }

}

//Rotates the boat 90 degrees in the specified direction (collision verification done in Game class)
bool Boat::rotate_boat(int dir)
{
    if(dir != m_dir) //Makes sure the move is not useless
    {
        m_dir= dir;
        return true;
    }
    else{ return false; } //if the move is useless the return is false
}

