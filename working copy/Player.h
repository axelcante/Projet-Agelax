#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

///Player class
class Player:
    {
    private:
        int m_player_number;
        bool m_isLost;

    public:
        //constructeur par défaut
        Player();
        //constructeur surchargé
        Player(int m_player_number, bool m_isLost)
        //destructeur
        ~Player();

        //getters
        int getPlayer_number()const;
        bool getIsLost()const;

        //setters
        void setPlayerNumber(int player_number);
        void setIsLost(bool isLost);

        //methods

    };

#endif // PLAYER_H_INCLUDED
