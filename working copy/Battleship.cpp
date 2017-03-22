#include "Battleship.h"

//Constructor
Battleship::Battleship(): Boat()
{

}

//Is the boat currently on the specified case?
bool Battleship::isHit(int pos_i, int pos_j)
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
            return false;
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
            return false;
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
            return false;
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
            return false;
            break;

        default: return false;

    }
}

//Is the boat dead?
bool Battleship::isDead()
{
    if(m_hit_count==m_length) {return true;}
    else {return false;}
}
