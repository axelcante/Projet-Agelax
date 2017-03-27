#include "Boat.h"

//Default constructor
Boat::Boat(){}

//Overloaded constructor
Boat::Boat(int pos_i, int pos_j, int dir, int hit_count, int length)
{
  m_pos_i = pos_i;
  m_pos_j = pos_j;
  m_dir = dir;
  m_hit_count = hit_count;
  m_length = length;
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
int Boat::get_length() { return m_length; }

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
        if(m_dir==(UP || DOWN)) { m_pos_j--; return true; } //returns true is all went well
        else return false; //returns false if the boat is not corectly aligned with the specified direction
        break;
    case RIGHT:
        if(m_dir==(RIGHT || LEFT)) { m_pos_i++; return true; }
        else return false;
        break;
    case DOWN:
        if(m_dir==(UP || DOWN)) { m_pos_j++; return true; }
        else return false;
        break;
    case LEFT:
        if(m_dir==(RIGHT || LEFT)) { m_pos_i--; return true; }
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

//Is the boat hit on the specified case?
bool Boat::isHit(int pos_i, int pos_j)
{
    switch(m_dir)
    {
        case UP:
            for(int i=0; i<m_length; i++)
            {
                //Only j varies
                if(pos_i== m_pos_i && pos_j== m_pos_j-i)
                {
                    //If the boat is not already hit on that spot
                    if(!m_hit_map[i])
                    {
                        //Set the spot as hit on the hit map
                        m_hit_map[i]= true;
                        //The boat is hit: return true
                        return true;
                    }

                }
            }
            return false; //If the boat wasn't hit return false
            break;

        case DOWN:
            for(int i=0; i<m_length; i++)
            {
                //Only j varies
                if(pos_i== m_pos_i && pos_j== m_pos_j+i)
                {
                    //If the boat is not already hit on that spot
                    if(!m_hit_map[i])
                    {
                        //Set the spot as hit on the hit map
                        m_hit_map[i]= true;
                        //The boat is hit: return true
                        return true;
                    }
                }
            }
            return false; //If the boat wasn't hit return false
            break;

        case RIGHT:
            for(int i=0; i<m_length; i++)
            {
                //Only i varies
                if(pos_j== m_pos_j && pos_i== m_pos_i+i)
                {
                    //If the boat is not already hit on that spot
                    if(!m_hit_map[i])
                    {
                        //Set the spot as hit on the hit map
                        m_hit_map[i]= true;
                        //The boat is hit: return true
                        return true;
                    }
                }
            }
            return false; //If the boat wasn't hit return false
            break;

        case LEFT:
            for(int i=0; i<m_length; i++)
            {
                //Only i varies
                if(pos_j== m_pos_j && pos_i== m_pos_i-i)
                {
                    //If the boat is not already hit on that spot
                    if(!m_hit_map[i])
                    {
                        //Set the spot as hit on the hit map
                        m_hit_map[i]= true;
                        //The boat is hit: return true
                        return true;
                    }
                }
            }
            return false; //If the boat wasn't hit return false
            break;

        default: return false;

    }
}

//Is the boat on that specified spot? If yes return true (used for conflict testing)
bool Boat::isOnThatSpot(int pos_i, int pos_j)
{
    switch(m_dir)
    {
        case UP:
            for(int i=0; i<m_length; i++)
            {
                //Only j varies
                if(pos_i== m_pos_i && pos_j== m_pos_j-i)
                {
                    //The boat is hit: return true
                    return true;
                }
            }
            return false; //If the boat wasn't hit return false
            break;

        case DOWN:
            for(int i=0; i<m_length; i++)
            {
                //Only j varies
                if(pos_i== m_pos_i && pos_j== m_pos_j+i)
                {
                    //The boat is hit: return true
                    return true;
                }
            }
            return false; //If the boat wasn't hit return false
            break;

        case RIGHT:
            for(int i=0; i<m_length; i++)
            {
                //Only i varies
                if(pos_j== m_pos_j && pos_i== m_pos_i+i)
                {
                    //The boat is hit: return true
                    return true;
                }
            }
            return false; //If the boat wasn't hit return false
            break;

        case LEFT:
            for(int i=0; i<m_length; i++)
            {
                //Only i varies
                if(pos_j== m_pos_j && pos_i== m_pos_i-i)
                {
                    //The boat is hit: return true
                    return true;
                }
            }
            return false; //If the boat wasn't hit return false
            break;

        default: return false;

    }
}

//Is the boat dead?
bool Boat::isDead()
{
    if(m_hit_count==m_length) {return true;}
    else {return false;}
}


