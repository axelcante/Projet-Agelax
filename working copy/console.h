#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <fstream>
#include <istream>

//Mr Diedler's code, originally for last year's Snoopy project

enum Color
{
    COLOR_BLACK = 0,
    COLOR_WHITE = 1,
    COLOR_RED = 2,
    COLOR_GREEN = 3,
    COLOR_BLUE = 4,
    COLOR_YELLOW = 5,
    COLOR_PURPLE = 6,
    COLOR_DEFAULT = 7, // gris couleur de base de la console
};

class Console
{
    private:
        // Empecher la cr�ation
        Console();
        ~Console();

        // Empecher la copie d'objet...
        Console& operator= (const Console&){ return *this;}
        Console (const Console&){}

        // Attributs
        static Console* m_instance;

        // M�thodes priv�es
        void _setColor(int front, int back);
    public:
        // M�thodes statiques (publiques)
        static Console* getInstance();
        static void deleteInstance();

        // M�thodes publiques
        void gotoLigCol(int lig, int col);
        bool ifKeyboardPressed();
        char getInputKey();
        void setColor(Color col);
        void ShowConsoleCursor(bool showFlag); //n'affiche plus le curseur de gotoligcol pour ne pas avoir de clignotement a l'�cran

};

struct console
  {
  console( unsigned width, unsigned height )
    {
    SMALL_RECT r;
    COORD      c;
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );

    r.Left   =
    r.Top    = 0;
    r.Right  = width -1;
    r.Bottom = height -1;
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

  void color( WORD color = 0x07 )
    {
    SetConsoleTextAttribute( hConOut, color );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  };

#endif // CONSOLE_H_INCLUDED
