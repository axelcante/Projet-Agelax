#include <iostream>
#include <windows.h>
#include <vector>
#include "console.h"
#include "Game.h"

using namespace std;

int main()
{
    console con(190, 70);
    ///La partie du code lie a la gestion de la console a entierement ete cree par Mr Diedler, dans le cadre du cours de C++ ING2
    //Creation du pointeur conso pour gerer la console
    Console* conso = Console::getInstance(); //Allocation memoire du pointeur sur console
    conso->setColor(COLOR_DEFAULT);
    conso->ShowConsoleCursor(false); //On rend le curseur de la console invisible pour ne pas avoir de clignotements

    //Game creation
    Game game;
    game.playMenu(conso);
    conso->deleteInstance();
}
