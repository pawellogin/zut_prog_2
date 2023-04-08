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
#include "player.h"

using namespace std;

class game {

	int kolejka;
	vector<int> Kolo;

	string haslo; // = "wielka antarktyda";
	string proba;
	char literka;
	int n;
	int maska[100];
	int suma = 0;
	int zgadl = 0;
	int sa_spolgloski = 0;
	int kwota = 0;
	char wybor;
	string rezultat;
	vector<string> hasla;

	ifstream strum;

	friend class player;
public:
	game() {
		srand(time(NULL));
		kolejka = 0;
		Kolo = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
	}

	int jestSamogloska(char c)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
			return 1;
		else
			return 0;

	}

	char WczytajZnak()
	{
		string letter;
		cin >> letter;

		while (letter.length() != 1)
		{
			cout << endl << "Type a single letter and press <enter>: ";
			cin >> letter;
		}

		for (auto& c : letter)  // & zapamietuje modyfikacje w petli & - referencja
			c = toupper(c);

		return letter[0];

	}

	char WczytajWybor()
	{
		char wybor;
		wybor = WczytajZnak();

		while (wybor != '1' && wybor != '2')
		{
			cout << endl << "Wybierz [1-2]: ";
			cin >> wybor;
		}

		return wybor;

	}

	void loadpassword() {

		strum.open("dane.txt");

		while (!strum.eof()) {
			string temp;
			getline(strum, temp);
			hasla.push_back(temp);
		}
		strum.close();

		haslo = hasla[rand() % hasla.size()];

		for (int i = 0; i < haslo.size(); i++)
		{
			if (haslo[i] == ' ')
				maska[i] = 0;
			else
				maska[i] = 1;
		}
	}

	void printpasswords() {
		for (string item : hasla)
			cout << item << endl;
	}

};