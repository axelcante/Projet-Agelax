#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

///Player class
class Player
    {
    private:
        int m_player_number;
        bool m_isLost;

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

        //Setters
        void setPlayerNumber(int player_number);
        void setIsLost(bool isLost);

        ///Methods

    };

#endif // PLAYER_H_INCLUDED
