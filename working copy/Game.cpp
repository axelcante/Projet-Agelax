#include "Game.h"
#include <string.h>

//Default constructor
Game::Game() {}
//Destructor
Game::~Game() {}

void Game::initializeBoard(bool firstTime)
{
    for (int i = 0; i < NBLIGNES; i++)
    {
        for (int j = 0; j < NBCOLS; j++)
        {
            m_board_player[i][j] = ' ';
            if(firstTime)
            {
                m_player_1.setShotsFired(i, j, ' ');
                m_player_2.setShotsFired(i, j, ' ');
            }
        }
    }
}

//Method that will the m_board_player board with the correct ships
void Game::fillPlayerBoard(Player player)
{
    for (int i = 0; i < NUMBER_OF_BOATS; i++)
    {
        switch(i)
        {
        case 0:
            m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i] = 'B';
            switch(player.m_boats[i].m_dir)
            {
            case UP:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j-j][player.m_boats[i].m_pos_i] = 'B';
                }
                break;
            case RIGHT:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i+j] = 'B';
                }
                break;
            case DOWN:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j+j][player.m_boats[i].m_pos_i] = 'B';
                }
                break;
            case LEFT:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i-j] = 'B';
                }
                break;
            }
            break;
        case 1:
        case 2:
            m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i] = 'C';
            switch(player.m_boats[i].m_dir)
            {
            case UP:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j-j][player.m_boats[i].m_pos_i] = 'C';
                }
                break;
            case RIGHT:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i+j] = 'C';
                }
                break;
            case DOWN:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j+j][player.m_boats[i].m_pos_i] = 'C';
                }
                break;
            case LEFT:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i-j] = 'C';
                }
                break;
            }
            break;
        case 3:
        case 4:
        case 5:
            m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i] = 'D';
            switch(player.m_boats[i].m_dir)
            {
            case UP:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j-j][player.m_boats[i].m_pos_i] = 'D';
                }
                break;
            case RIGHT:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i+j] = 'D';
                }
                break;
            case DOWN:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j+j][player.m_boats[i].m_pos_i] = 'D';
                }
                break;
            case LEFT:
                for(int j = 0; j < player.m_boats[i].m_length; j++)
                {
                    m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i-j] = 'D';
                }
                break;
            }
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            m_board_player[player.m_boats[i].m_pos_j][player.m_boats[i].m_pos_i] = 'S';
            break;
        }
//        system("cls");
//        std::cout << m_player_1.m_boats[i].m_pos_i;
//        std::cout << m_player_2.m_boats[i].m_pos_i;
//        system("pause");
    }
}

//Method partly inspired by last year's Snoopy project - Axel CANTE / Juliette HEUANGTHEP
void Game::displayBoard(Console* conso, Player player)
{
    for(int i = 0; i < NUMBER_OF_BOATS; i++)
    {
        conso->gotoLigCol(POSLIGNE+18+i, POSCOL); std::cout << m_player_1.m_boats[i].m_dir << "  " << m_player_1.m_boats[i].m_pos_i+1 << "  " << m_player_1.m_boats[i].m_pos_j+1;
    }
    conso->setColor(COLOR_DEFAULT);
    int lines = 0;
    initializeBoard(false);
    ///fill player board with the relevant player's ships here
    fillPlayerBoard(player);

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
    std::cout << 'O';

    //Display the player's previous shots fired array
    lines = 0;
    conso->gotoLigCol(POSLIGNE, POSCOL*5);
    for (int i = 0; i < NBLIGNES; i++)
    {
        for (int j = 0; j < NBCOLS; j++)
        {
            std::cout << '|';
            std::cout << player.getShotsFired(i, j);
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
    std::cout << 'O';
    conso->gotoLigCol(POSLIGNE+30, POSCOL);
}

//This method will display all the necessary game information on the right of the game board
void Game::displayInfo(Console* conso, int player_number)
{
    conso->gotoLigCol(POSLIGNE*1.5, POSCOL*9);
    std::cout << "Player ";
    conso->setColor(COLOR_PURPLE);
    std::cout << player_number;
    conso->setColor(COLOR_DEFAULT);
    std::cout << "'s turn.";
    conso->gotoLigCol(POSLIGNE*2, POSCOL*9);
    conso->setColor(COLOR_GREEN);
    std::cout << "Pick an action :";
    conso->setColor(COLOR_DEFAULT);
    conso->gotoLigCol(POSLIGNE*2.5, POSCOL*9.2);
    std::cout << "1. Fire";
    conso->gotoLigCol(POSLIGNE*2.75, POSCOL*9.2);
    std::cout << "2. Move a ship";
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

void Game::displayTutorial(Console* conso)
{
    system("CLS");
    conso->setColor(COLOR_DEFAULT);
    conso->gotoLigCol(POSLIGNE, POSCOL);
    conso->setColor(COLOR_YELLOW);
    std::cout << "BATTLESHIPS - TUTORIAL";
    conso->setColor(COLOR_DEFAULT);
    conso->gotoLigCol(POSLIGNE+4, POSCOL);
    std::cout << "This is a modern Battleships game.";
    conso->gotoLigCol(POSLIGNE+6, POSCOL);
    std::cout << "Players will take turns to play against each other.";
    conso->gotoLigCol(POSLIGNE+8, POSCOL);
    std::cout << "The goal of the game is to sink the other player's ships.";
    conso->gotoLigCol(POSLIGNE+10, POSCOL);
    std::cout << "Each turn, the player will have a number of actions available to him.";
    conso->gotoLigCol(POSLIGNE+12, POSCOL);
    std::cout << "Depending on which ships are available to him : 1. FIRE, 2. MOVE";
    conso->gotoLigCol(POSLIGNE+14, POSCOL);
    std::cout << "If the player chooses to FIRE, he will then be asked to input a letter (column) followed by a number (line).";
    conso->gotoLigCol(POSLIGNE+16, POSCOL);
    std::cout << "If the player chooses to MOVE, he will first select a ship, then a direction to move in.";
}

//Method partly inspired by last year's Snoopy Project - Axel CANTE / Juliette HEUANGTHEP
void Game::playMenu(Console* conso)
{
    int menu_choice = 1;
    bool quit_game = false; //Bool that will decide whether or not to quit the game
    displayMenu(conso);
    styleMenu(menu_choice, conso);

    while(!quit_game)
    {
        if(conso->ifKeyboardPressed())
        {
            int key = conso->getInputKey();
            if(key == 115)
            {
                menu_choice++;
                if(menu_choice == 5) menu_choice = 4; //make sure the player choice stays between 1 and 3
                styleMenu(menu_choice, conso);
            }
            if(key == 122 || key == 119)
            {
                menu_choice--;
                if(menu_choice == 0) menu_choice = 1;
                styleMenu(menu_choice, conso);
            }

            if(menu_choice == 1 && key == 13) //start the game
            {
                initializeBoard(true);
                m_player_1.initializeBoats();
                m_player_2.initializeBoats();
                system("cls");
                playGame(conso);
            }
            if(menu_choice == 4 && key == 13) //quit the game
            {
                quit_game = true;
            }

            if(key == 27) //"Esc" to quit the game
            {
                quit_game = true;
            }

            if(menu_choice == 2 && key == 13) //load a game
            {

            }

            if(menu_choice == 3 && key == 13) //show tutorial
            {
                displayTutorial(conso);
                conso->gotoLigCol(POSLIGNE+25, POSCOL); system("pause");
                system("cls");
                displayMenu(conso);
                menu_choice = 1;
                styleMenu(menu_choice, conso);
            }
        }
    }
}

void Game::playGame(Console* conso) //Function that will play the game
{
    system("cls");

    int player_number = 2;
    std::string command;
    char command_char;
    int command_int;
    bool quit = false;
    bool endturn = true;

    while(!quit)
    {
        if(endturn)
        {
            system("cls");
            endturn = false;

            //Changement de joueur
            if(player_number == 1) player_number = 2;
                else player_number = 1;

            //Afficher le joueur correspondant
            if(player_number == 1) displayBoard(conso, m_player_1);
                else displayBoard(conso, m_player_2);

            displayInfo(conso, player_number);
            conso->gotoLigCol(POSLIGNE*3, POSCOL*9.2);
            std::cout << "           ";

            //Make sure the player input is not an invalid input
            do
            {
                conso->gotoLigCol(POSLIGNE*3, POSCOL*9.2);
                std::cout << "         ";
                conso->gotoLigCol(POSLIGNE*3, POSCOL*9.2);
                std::cin >> command;
            } while((command != "quit") && (command != "1") && (command != "2"));

            //Return to the main menu
            if(command == "quit")
            {
                quit = true;
                system("cls");
                displayMenu(conso);
                styleMenu(1, conso);
            } else if(command == "2")
            {
                conso->gotoLigCol(POSLIGNE*2.5, POSCOL*9.2);
                std::cout << "                 ";
                conso->gotoLigCol(POSLIGNE*2.75, POSCOL*9.2);
                std::cout << "2. Move a ship";
                ///move a boat here
            } else if(command == "1")
            {
                conso->gotoLigCol(POSLIGNE*2.5, POSCOL*9.2);
                std::cout << "1. Fire";
                conso->gotoLigCol(POSLIGNE*2.75, POSCOL*9.2);
                conso->setColor(COLOR_YELLOW);
                std::cout << "Select a letter first.";
                conso->setColor(COLOR_DEFAULT);
                conso->gotoLigCol(POSLIGNE*3, POSCOL*9.2);
                std::cout << "                     ";

                //Make sure the player's targeted column is below O and above A
                do
                {
                    conso->gotoLigCol(POSLIGNE*3, POSCOL*9.2);
                    std::cout << "        ";
                    conso->gotoLigCol(POSLIGNE*3, POSCOL*9.2);
                    std::cin >> command_char;
                } while((command_char < 'A' || command_char > 'O') && (command_char < 'a' || command_char > 'o'));

                //Make sure the player's targeted line is above 1 and below 15
                conso->gotoLigCol(POSLIGNE*2.75, POSCOL*9.2);
                conso->setColor(COLOR_RED);
                std::cout << "Select a number next. ";
                conso->setColor(COLOR_DEFAULT);
                do
                {
                    conso->gotoLigCol(POSLIGNE*3, POSCOL*9.4);
                    std::cout << "       ";
                    conso->gotoLigCol(POSLIGNE*3, POSCOL*9.4);
                    std::cin >> command_int;
                } while (command_int < 1 || command_int > 15);

                //this is where the player's command is treated by the game. Once this is done, the turn is passed

                if(player_number == 1)
                {
                    if(shotHasTouched(m_player_1, convert(command_char), command_int-1))
                        m_player_1.setShotsFired(command_int-1, convert(command_char), 219);
                    else m_player_1.setShotsFired(command_int-1, convert(command_char), 177);
                    displayBoard(conso, m_player_1);
                } else
                {
                    if(shotHasTouched(m_player_2, convert(command_char), command_int-1))
                        m_player_2.setShotsFired(command_int-1, convert(command_char), 219);
                    else m_player_2.setShotsFired(command_int-1, convert(command_char), 177);
                    displayBoard(conso, m_player_2);
                }
                conso->gotoLigCol(POSLIGNE+25, POSCOL); system("pause");
                endturn = true;


            }
        }
    }
}

//Method that will convert a character input into an int (for the shooting function)
int Game::convert(char a)
{
    int integer = 0;

    if(a == 'A' || a == 'a') integer = 0;
    if(a == 'B' || a == 'b') integer = 1;
    if(a == 'C' || a == 'c') integer = 2;
    if(a == 'D' || a == 'd') integer = 3;
    if(a == 'E' || a == 'e') integer = 4;
    if(a == 'F' || a == 'f') integer = 5;
    if(a == 'G' || a == 'g') integer = 6;
    if(a == 'H' || a == 'h') integer = 7;
    if(a == 'I' || a == 'i') integer = 8;
    if(a == 'J' || a == 'j') integer = 9;
    if(a == 'K' || a == 'k') integer = 10;
    if(a == 'L' || a == 'l') integer = 11;
    if(a == 'M' || a == 'm') integer = 12;
    if(a == 'N' || a == 'n') integer = 13;
    if(a == 'O' || a == 'o') integer = 14;

    return integer;
}

////Method that will test whether or not a player's shot has touched the opponent's boat
bool Game::shotHasTouched(Player player, int pos_i, int pos_j) {
    if(player.getPlayer_number() == 1) {
        for(int i = 0; i < NUMBER_OF_BOATS; i++) {
            if(m_player_2.m_boats[i].isOnThatSpot(pos_i, pos_j)) {return true; system("pause");}
                else return false;
        }
    } else if(player.getPlayer_number() == 2) {
        for(int j = 0; j < NUMBER_OF_BOATS; j++) {
            if(m_player_1.m_boats[j].isOnThatSpot(pos_i, pos_j)) {return true; system("pause");}
                else return false;
        }
    }
    system("cls");
    std::cout << "bug";
    system("pause");
    return false;
}


///Method unused for the moment
//void Game::playerCommand(Console* conso, Player player, char command_char, int command_int)
//{
//    int converted_command_char = 0;
//    converted_command_char = convert(command_char);;
//    player.setShotsFired(command_int-1, converted_command_char, 219);
//    displayBoard(conso, player);
//}
