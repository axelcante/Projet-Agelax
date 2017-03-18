#include <iostream>
#include <windows.h>
#include <vector>
#include "console.h"

using namespace std;

int main()
{
    console con(170, 50);
    //Cr�ation du pointeur conso pour g�rer la console
    Console* conso = Console::getInstance(); //Allocation m�moire du pointeur sur console
    conso->ShowConsoleCursor(false); //On rend le curseur de la console invisible pour ne pas avoir de clignotements
    conso->deleteInstance();
}
