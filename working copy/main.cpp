#include <iostream>
#include <windows.h>
#include <vector>
#include "console.h"
#include "Game.h"

using namespace std;

int main()
{
    console con(190, 70);
    ///La partie du code li� � la gestion de la console a enti�rement �t� cr�� par Mr Diedler, dans le cadre du cours de C++ ING2
    //Cr�ation du pointeur conso pour g�rer la console
    Console* conso = Console::getInstance(); //Allocation m�moire du pointeur sur console
    conso->setColor(COLOR_DEFAULT);
    conso->ShowConsoleCursor(false); //On rend le curseur de la console invisible pour ne pas avoir de clignotements

    //Game creation
    Game game;
    game.playMenu(conso);
    conso->deleteInstance();
}
