#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Constantes.h"

///Player class
class Player
    {
    private:
        int m_player_number;
        bool m_isLost;
        //Table that keeps in memory each player's shots fired - public because is not important
        char m_shots_fired[NBLIGNES][NBCOLS];

    public:
        //Default constructor
        Player();
        //Overcharged constructor
        Player(int player_number, bool isLost);
        //Destructor
        ~Player();

        //Getters
        int getPlayer_number()const;
        bool getIsLost()const;
        char getShotsFired(int i, int j)const;

        //Setters
        void setPlayerNumber(int player_number);
        void setIsLost(bool isLost);
        void setShotsFired(int i, int j, char a);

        ///Methods

    };

#endif // PLAYER_H_INCLUDED
