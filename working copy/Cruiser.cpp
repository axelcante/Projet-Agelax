#include "Cruiser.h"

//Constructor
Cruiser::Cruiser(): Boat()
{
    for(int i=0; i<CRUISER_LENGTH; i++)
    {
        bool b= false;
        m_hit_map.push_back(b);
    }
}

Cruiser::Cruiser(int pos_i, int pos_j, int dir, int hit_count, int length)
{
  m_pos_i = pos_i;
  m_pos_j = pos_j;
  m_dir = dir;
  m_hit_count = hit_count;
  m_length = length;
}
//Destructor
Cruiser::~Cruiser()
{

}