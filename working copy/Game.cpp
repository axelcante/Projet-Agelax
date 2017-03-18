#include "Game.h"

//Default constructor
Game::Game() {}

Game::~Game() {}

void Game::displayBoard(Console* conso)
{
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
