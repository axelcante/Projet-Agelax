#include "Battleship.h"

//Is the boat currently on the specified case?
bool Battleship::isHit(int pos_i, int pos_j)
{
    switch(m_dir)
    {
        case UP:
        case DOWN:
            for(int i=0; i<m_length; i++)
            {
                //Faut coder la verification hit
                //Avec j qui varie
            }
            break;

        case RIGHT:
        case LEFT:
            for(int i=0; i<m_length; i++)
            {
                //Faut coder la verification hit
                //Avec i qui varie
            }
            break;

    }
}
