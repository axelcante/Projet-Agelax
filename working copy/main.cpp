#include <iostream>
#include <windows.h>
#include <vector>
#include "console.h"
#include "Game.h"

using namespace std;

int main()
{
    console con(190, 70);
    //Création du pointeur conso pour gérer la console
    Console* conso = Console::getInstance(); //Allocation mémoire du pointeur sur console
    conso->setColor(COLOR_DEFAULT);
    conso->ShowConsoleCursor(false); //On rend le curseur de la console invisible pour ne pas avoir de clignotements

    //Game creation
    Game game;
    game.displayBoard(conso);
    conso->deleteInstance();
}
