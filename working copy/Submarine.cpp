#include "Submarine.h"

//Constructor
Submarine::Submarine(): Boat()
{
    for(int i=0; i<SUBMARINE_LENGTH; i++)
    {
        bool b= false;
        m_hit_map.push_back(b);
    }
}

Submarine::Submarine(int pos_i, int pos_j, int dir, int hit_count, int length, std::string id)
{
  m_pos_i = pos_i;
  m_pos_j = pos_j;
  m_dir = dir;
  m_hit_count = hit_count;
  m_length = length;
  m_id = id;
}
//Destructor
Submarine::~Submarine()
{

}
