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

int main() {

	player player0("Bryanusz", 0);
	player player1("Jessica", 1);
	player player2("Nepomucen", 2);

	game game1;

	game1.loadpassword();
	game1.printpasswords();

	while (1) {

	}
}