#include "Cruiser.h"

//Constructor
Cruiser::Cruiser(): Boat()
{
}

Cruiser::Cruiser(int pos_i, int pos_j, int dir, int hit_count, int length, std::string id)
{
  m_pos_i = pos_i;
  m_pos_j = pos_j;
  m_dir = dir;
  m_hit_count = hit_count;
  m_length = length;
<<<<<<< HEAD
  for(int i=0; i<CRUISER_LENGTH; i++)
    {
        bool b= false;
        m_hit_map.push_back(b);
    }
=======
  m_id = id;
>>>>>>> c6441eff19eea56c54131c5c3ebcaace8591b87c
}
//Destructor
Cruiser::~Cruiser()
{

}
