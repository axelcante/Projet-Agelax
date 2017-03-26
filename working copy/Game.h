#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Player.h"
#include "console.h"

///Game class
class Game
{
public:
    //Players and board are declared publicly so that they are easier to access within the game's code
    Player m_player_1 = Player(1, false);
    Player m_player_2 = Player(2, false);
    char m_board_player[NBCOLS][NBLIGNES];
//    char m_board_game_1[NBCOLS][NBLIGNES];
//    char m_board_game_1[NBCOLS][NBLIGNES];

    //Default constructor
    Game();
    //Destructor
    ~Game();

    ///Methods related to the menu
    //Method that will run a menu giving the players options before playing the game
    void displayMenu(Console* conso);
    //Method that will make the meny more stylistic
    void styleMenu(int choice, Console* conso);
    //When called, this method will display the rules of the game
    void displayTutorial(Console* conso);
    //Method that will allow the player to navigate the menu and decide which action to take
    void playMenu(Console* conso);
    //Method that will allow players to play Battleships
    void playGame(Console* conso); ///For now, not used

    ///Methods related to the game board
    //Method that will intialize the board (empty)
    void initializeBoard();
    //Method that will display and update the game board depending on the player and actions taken before (movements, shots...)
    void displayBoard(Console* conso, Player player);
    //Method that will display current player information on the side of the game board
    void displayInfo(Console* conso, int player_number);

    //Method that will convert a char into a relevant int
    int convert(char a);
    ///Method unused for the moment
    //Method that will recieve the player's command and treat it accordingly
//    void playerCommand(Console* conso, Player player, char command_char, int command_int);
};

#endif // GAME_H_INCLUDED
