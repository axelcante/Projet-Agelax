#include "Battleship.h"

//Constructor
Battleship::Battleship(): Boat()
{
    for(int i=0; i<BATTLESHIP_LENGTH; i++)
    {
        bool b= false;
        m_hit_map.push_back(b);
    }
}

Battleship::Battleship(int pos_i, int pos_j, int dir, int hit_count, int length, std::string id)
{
  m_pos_i = pos_i;
  m_pos_j = pos_j;
  m_dir = dir;
  m_hit_count = hit_count;
  m_length = length;
  m_id = id;
}
//Destructor
Battleship::~Battleship()
{

}

////Is the boat hit on the specified case?
//bool Battleship::isHit(int pos_i, int pos_j)
//{
//    switch(m_dir)
//    {
//        case UP:
//            for(int i=0; i<m_length; i++)
//            {
//                //Only j varies
//                if(pos_i== m_pos_i && pos_j== m_pos_j-i)
//                {
//                    //If the boat is not already hit on that spot
//                    if(!m_hit_map[i])
//                    {
//                        //Set the spot as hit on the hit map
//                        m_hit_map[i]= true;
//                        //The boat is hit: return true
//                        return true;
//                    }
//
//                }
//            }
//            return false; //If the boat wasn't hit return false
//            break;
//
//        case DOWN:
//            for(int i=0; i<m_length; i++)
//            {
//                //Only j varies
//                if(pos_i== m_pos_i && pos_j== m_pos_j+i)
//                {
//                    //If the boat is not already hit on that spot
//                    if(!m_hit_map[i])
//                    {
//                        //Set the spot as hit on the hit map
//                        m_hit_map[i]= true;
//                        //The boat is hit: return true
//                        return true;
//                    }
//                }
//            }
//            return false; //If the boat wasn't hit return false
//            break;
//
//        case RIGHT:
//            for(int i=0; i<m_length; i++)
//            {
//                //Only i varies
//                if(pos_j== m_pos_j && pos_i== m_pos_i+i)
//                {
//                    //If the boat is not already hit on that spot
//                    if(!m_hit_map[i])
//                    {
//                        //Set the spot as hit on the hit map
//                        m_hit_map[i]= true;
//                        //The boat is hit: return true
//                        return true;
//                    }
//                }
//            }
//            return false; //If the boat wasn't hit return false
//            break;
//
//        case LEFT:
//            for(int i=0; i<m_length; i++)
//            {
//                //Only i varies
//                if(pos_j== m_pos_j && pos_i== m_pos_i-i)
//                {
//                    //If the boat is not already hit on that spot
//                    if(!m_hit_map[i])
//                    {
//                        //Set the spot as hit on the hit map
//                        m_hit_map[i]= true;
//                        //The boat is hit: return true
//                        return true;
//                    }
//                }
//            }
//            return false; //If the boat wasn't hit return false
//            break;
//
//        default: return false;
//
//    }
//}
//
////Is the boat on that specified spot? If yes return true (used for conflict testing)
//bool Battleship::isOnThatSpot(int pos_i, int pos_j)
//{
//    switch(m_dir)
//    {
//        case UP:
//            for(int i=0; i<m_length; i++)
//            {
//                //Only j varies
//                if(pos_i== m_pos_i && pos_j== m_pos_j-i)
//                {
//                    //The boat is hit: return true
//                    return true;
//                }
//            }
//            return false; //If the boat wasn't hit return false
//            break;
//
//        case DOWN:
//            for(int i=0; i<m_length; i++)
//            {
//                //Only j varies
//                if(pos_i== m_pos_i && pos_j== m_pos_j+i)
//                {
//                    //The boat is hit: return true
//                    return true;
//                }
//            }
//            return false; //If the boat wasn't hit return false
//            break;
//
//        case RIGHT:
//            for(int i=0; i<m_length; i++)
//            {
//                //Only i varies
//                if(pos_j== m_pos_j && pos_i== m_pos_i+i)
//                {
//                    //The boat is hit: return true
//                    return true;
//                }
//            }
//            return false; //If the boat wasn't hit return false
//            break;
//
//        case LEFT:
//            for(int i=0; i<m_length; i++)
//            {
//                //Only i varies
//                if(pos_j== m_pos_j && pos_i== m_pos_i-i)
//                {
//                    //The boat is hit: return true
//                    return true;
//                }
//            }
//            return false; //If the boat wasn't hit return false
//            break;
//
//        default: return false;
//
//    }
//}
//
////Is the boat dead?
//bool Battleship::isDead()
//{
//    if(m_hit_count==m_length) {return true;}
//    else {return false;}
//}
