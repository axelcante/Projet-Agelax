#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Player.h"
#include "console.h"
#include "Constantes.h"

///Game class
class Game
{
public:
    //Players and board are declared publicly so that they are easier to access within the game's code
    Player m_player_1 = Player(1, false);
    Player m_player_2 = Player(2, false);
    char m_board_player[NBCOLS][NBLIGNES];
    char m_board_game[NBCOLS][NBLIGNES];

    //Default constructor
    Game();
    //Destructor
    ~Game();

    ///Methods
    //Method that will display and update the game board depending on the player and actions taken before (movements, shots...)
    void displayBoard(Console* conso);
};

#endif // GAME_H_INCLUDED
