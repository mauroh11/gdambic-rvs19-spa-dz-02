#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;

	bool korisnikov_odabir;
	cout << endl;

	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();

		cout << endl << "> Dalje? (1/0): ";
		cin >> korisnikov_odabir;
	} while (korisnikov_odabir);

	if (korisnikov_odabir == 0)
	{
		cout << endl << "> Smrt." << endl;
	}

	return 0;
}