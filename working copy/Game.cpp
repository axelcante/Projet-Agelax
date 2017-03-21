#include "Game.h"

//Default constructor
Game::Game() {}

Game::~Game() {}

//Method partly inspired by last year's Snoopy project - Axel CANTE / Juliette HEUANGTHEP
void Game::displayBoard(Console* conso)
{
    conso->setColor(COLOR_DEFAULT);
    int lines = 0;

    //Entering necessary information in the array
    for (int i = 0; i < NBLIGNES; i++)
    {
        for (int j = 0; j < NBCOLS; j++)
        {
            m_board_player[i][j] = ' ';
            m_board_game[i][j] = ' ';
        }
    }

    displayInfo(conso, 1);

    //Displaying the player screen
    conso->gotoLigCol(POSLIGNE, POSCOL);
    for (int i = 0; i < NBLIGNES; i++)
    {
        for (int j = 0; j < NBCOLS; j++)
        {
            std::cout << '|';
            std::cout << m_board_player[i][j];
        }
        std::cout << '|';
        lines++;
        conso->gotoLigCol(POSLIGNE+lines, POSCOL);
    }
    lines = 0;
    for (int i = 0; i < NBLIGNES; i++)
    {
        conso->gotoLigCol(POSLIGNE+lines, POSCOL-3);
        lines++;
        std::cout << i+1;
    }
    conso->gotoLigCol(POSLIGNE-1, POSCOL+1);
    std::cout << 'A';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+3);
    std::cout << 'B';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+5);
    std::cout << 'C';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+7);
    std::cout << 'D';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+9);
    std::cout << 'E';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+11);
    std::cout << 'F';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+13);
    std::cout << 'G';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+15);
    std::cout << 'H';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+17);
    std::cout << 'I';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+19);
    std::cout << 'J';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+21);
    std::cout << 'K';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+23);
    std::cout << 'L';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+25);
    std::cout << 'M';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+27);
    std::cout << 'N';
    conso->gotoLigCol(POSLIGNE-1, POSCOL+29);
    std::cout << '0';

    //Display the game array
    lines = 0;
    conso->gotoLigCol(POSLIGNE, POSCOL*5);
    for (int i = 0; i < NBLIGNES; i++)
    {
        for (int j = 0; j < NBCOLS; j++)
        {
            std::cout << '|';
            std::cout << m_board_game[i][j];
        }
        std::cout << '|';
        lines++;
        conso->gotoLigCol(POSLIGNE+lines, POSCOL*5);
    }
    lines = 0;
    for (int i = 0; i < NBLIGNES; i++)
    {
        conso->gotoLigCol(POSLIGNE+lines, POSCOL*5-3);
        lines++;
        std::cout << i+1;
    }
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+1);
    std::cout << 'A';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+3);
    std::cout << 'B';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+5);
    std::cout << 'C';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+7);
    std::cout << 'D';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+9);
    std::cout << 'E';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+11);
    std::cout << 'F';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+13);
    std::cout << 'G';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+15);
    std::cout << 'H';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+17);
    std::cout << 'I';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+19);
    std::cout << 'J';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+21);
    std::cout << 'K';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+23);
    std::cout << 'L';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+25);
    std::cout << 'M';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+27);
    std::cout << 'N';
    conso->gotoLigCol(POSLIGNE-1, POSCOL*5+29);
    std::cout << '0';

    conso->gotoLigCol(POSLIGNE+30, POSCOL);

//    //Drawing the board outline
//    char horizontal=205,vertical=186;
//    char C_right_top=187,C_right_bottom=188;
//    char C_left_top=201,C_left_bottom=200;
//    int shift = 0;
//
//    conso->gotoLigCol(POSLIGNE-2, POSCOL-1);
//    conso->setColor(COLOR_WHITE);
//    for (int i = 0; i < N_COLONNES; i ++)
//    {
//        std::cout << horizontal;
//    }
//    conso->gotoLigCol(POSLIGNE+N_LIGNES-1, POSCOL-1);
//    for (int i = 0; i < N_COLONNES; i++)
//    {
//        std::cout << horizontal;
//    }
//    for (int i = 0; i < N_LIGNES; i++)
//    {
//        conso->gotoLigCol(POSLIGNE+shift-1, POSCOL-2);
//        std::cout << vertical;
//        shift++;
//    }
//    shift = 0;
//    for (int i = 0; i < N_LIGNES; i++)
//    {
//        conso->gotoLigCol(POSLIGNE+shift-1, POSCOL+N_COLONNES-1);
//        std::cout << vertical;
//        shift++;
//    }
//
//    //Outline corners
//    conso->gotoLigCol(POSLIGNE-2, POSCOL-2);
//    std::cout << C_left_top;
//    conso->gotoLigCol(POSLIGNE-2, POSCOL+N_COLONNES-1);
//    std::cout << C_right_top;
//    conso->gotoLigCol(POSLIGNE+N_LIGNES-1, POSCOL-2);
//    std::cout << C_left_bottom;
//    conso->gotoLigCol(POSLIGNE+N_LIGNES-1, POSCOL+N_COLONNES-1);
//    std::cout << C_right_bottom;
//    conso->setColor(COLOR_DEFAULT);
}

//This method will display all the necessary game information on the right of the game board
void Game::displayInfo(Console* conso, int player_number)
{
    conso->gotoLigCol(POSLIGNE*1.5, POSCOL*9);
    std::cout << "Player " << player_number << "'s turn.";
    conso->gotoLigCol(POSLIGNE*2, POSCOL*9);
    std::cout << "Pick an action :";
    conso->gotoLigCol(POSLIGNE*2.5, POSCOL*9.2);
    std::cout << "1. Fire";
    conso->gotoLigCol(POSLIGNE*2.75, POSCOL*9.2);
    std::cout << "2. Move a ship";
    conso->gotoLigCol(POSLIGNE*2.9, POSCOL*9.2);
    std::cout << "3. Flare";
}

//Method partly inspired by last year's Snoopy project - Axel CANTE / Juliette HEUANGTHEP
void Game::displayMenu(Console* conso)
{
    system("cls");

    conso->gotoLigCol(POSLIGNE,POSCOL+20);       //normal menu display
    std::cout << "Welcome to Battleships!";
    conso->gotoLigCol(POSLIGNE+2,POSCOL);
    std::cout << "A game crated by Axel CANTE, Agathe HENRY and Eliott SEGARD !";
    conso->gotoLigCol(POSLIGNE+4,POSCOL+5);
    std::cout << "Use the 'Z' and 'S' keys to navigate around the menu.";
    conso->setColor(COLOR_DEFAULT);
    conso->gotoLigCol(POSLIGNE+8,POSCOL+10);
    std::cout << "1. New Game";
    conso->gotoLigCol(POSLIGNE+10,POSCOL+10);
    std::cout << "2. Load Game";
    conso->gotoLigCol(POSLIGNE+12,POSCOL+10);
    std::cout << "3. Tutorial";
    conso->gotoLigCol(POSLIGNE+14,POSCOL+10);
    std::cout << "4. Quit Game";
    conso->gotoLigCol(POSLIGNE+20,POSCOL+10);
}

//Menu that will display different effects depending on the player choices (on the menu)
//Method partly inspired by last year's Snoopy projet - Axel CANTE / Juliette HEUANGTHEP
void Game::styleMenu(int choice, Console* conso)
{
    switch(choice)
    {
    case 1 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOL+10);
        std::cout << "1. New Game";
        conso->gotoLigCol(POSLIGNE+10,POSCOL+10);
        std::cout << "2. Load Game";
        conso->gotoLigCol(POSLIGNE+12,POSCOL+10);
        std::cout << "3. Tutorial";
        conso->gotoLigCol(POSLIGNE+14,POSCOL+10);
        std::cout << "4. Quit Game";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+8,POSCOL+10);
        std::cout << "1. New Game";
        break;

    case 2 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOL+10);
        std::cout << "1. New Game";
        conso->gotoLigCol(POSLIGNE+10,POSCOL+10);
        std::cout << "2. Load Game";
        conso->gotoLigCol(POSLIGNE+12,POSCOL+10);
        std::cout << "3. Tutorial";
        conso->gotoLigCol(POSLIGNE+14,POSCOL+10);
        std::cout << "4. Quit Game";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+10,POSCOL+10);
        std::cout << "2. Load Game";
        break;

    case 3 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOL+10);
        std::cout << "1. New Game";
        conso->gotoLigCol(POSLIGNE+10,POSCOL+10);
        std::cout << "2. Load Game";
        conso->gotoLigCol(POSLIGNE+12,POSCOL+10);
        std::cout << "3. Tutorial";
        conso->gotoLigCol(POSLIGNE+14,POSCOL+10);
        std::cout << "4. Quit Game";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+12,POSCOL+10);
        std::cout << "3. Tutorial";
        break;

    case 4 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOL+10);
        std::cout << "1. New Game";
        conso->gotoLigCol(POSLIGNE+10,POSCOL+10);
        std::cout << "2. Load Game";
        conso->gotoLigCol(POSLIGNE+12,POSCOL+10);
        std::cout << "3. Tutorial";
        conso->gotoLigCol(POSLIGNE+14,POSCOL+10);
        std::cout << "4. Quit Game";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+14,POSCOL+10);
        std::cout << "4. Quit Game";
    }
}

//Method partly inspired by last year's Snoopy Project - Axel CANTE / Juliette HEUANGTHEP
void Game::playMenu(Console* conso)
{
    int menu_choice = 1;
    bool quit = false; //Bool that will decide whether or not to quit the game
    displayMenu(conso);
    styleMenu(menu_choice, conso);

    while(!quit)
    {
        if(conso->ifKeyboardPressed())
        {
            int key = conso->getInputKey();
            if(key==115)
            {
                menu_choice++;
                if(menu_choice == 5) menu_choice = 4; //make sure the player choice stays between 1 and 3
                styleMenu(menu_choice, conso);
            }
            if(key == 122)
            {
                menu_choice--;
                if(menu_choice == 0) menu_choice = 1;
                styleMenu(menu_choice, conso);
            }

            if(menu_choice == 1 && key == 13) //start the game
            {
                system("cls");
                displayBoard(conso);
                displayInfo(conso, 1);
            }

            if(menu_choice == 4 && key == 13) //quit the game
            {
                quit = true;
            }

            if(key == 27) //"Esc" to quit the game
            {
                quit = true;
            }

            if(menu_choice == 2 && key == 13) //load a game
            {

            }

            if(menu_choice == 3 && key == 13) //show tutorial
            {
                displayTutorial(conso);
            }
        }
    }
}

void Game::displayTutorial(Console* conso)
{
    system("CLS");
    conso->setColor(COLOR_DEFAULT);
    conso->gotoLigCol(POSLIGNE, POSCOL);
    std::cout << "BATTLESHIPS - TUTORIAL";
    conso->gotoLigCol(POSLIGNE+4, POSCOL);
    std::cout << "This is a modern Battleships game.";
    conso->gotoLigCol(POSLIGNE+6, POSCOL);
    std::cout << "Players will take turns to play against each other.";
    conso->gotoLigCol(POSLIGNE+8, POSCOL);
    std::cout << "The goal of the game is to sink the other player's ships.";
    conso->gotoLigCol(POSLIGNE+10, POSCOL);
    std::cout << "Each turn, the player will have a number of actions available to him.";
    conso->gotoLigCol(POSLIGNE+12, POSCOL);
}
