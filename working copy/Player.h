#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Constantes.h"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "Boat.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"

///Player class
class Player
    {
    private:
        int m_player_number;
        bool m_isLost;
        //Table that keeps in memory each player's shots fired - public because is not important
        char m_shots_fired[NBLIGNES][NBCOLS];
        //Vector that contains the player's boats


    public:
        //Default constructor
        Player();
        //Overcharged constructor
        Player(int player_number, bool isLost);
        //Destructor
        ~Player();
        std::vector<Boat> m_boats;

        //Getters
        int getPlayer_number()const;
        bool getIsLost()const;
        char getShotsFired(int i, int j)const;

        //Setters
        void setPlayerNumber(int player_number);
        void setIsLost(bool isLost);
        void setShotsFired(int i, int j, char a);

        ///Methods
        //Method that randomly places the boats
        void initializeBoats();

    };

#endif // PLAYER_H_INCLUDED
