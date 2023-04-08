#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>  
#include <fstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <locale.h>
#include "game.h"

using namespace std;

static int id;

class player
{
    string imie;
    int kasa;
    int portfel; //kasa z wygranych rund


public:

    player(string name, int id) {
        imie = name;
        kasa = 0;
        portfel = 0;

        id++;
    }

    void textPlayers(game game1)
    {
        int i;
        std::cout << "\n";
        for (i = 0; i < 3; i++) {
            if (i == game1.kolejka) {
                cout << "\033[1;34m";
            }
            cout << imie << "\t" << kasa << "\n";
            cout << "\033[0m";

        }
        cout << "\n";
    }

    ~player() {
        id--;
    }
};


