#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "consoleFunctions.hpp"
// Colors: Black Red Green Yellow Blue Magenta Cyan White
// Box Chars: Hori Very ElbowBR ElbowBL ElbowTR ElbowTL TeeRight TeeLeft TeeDown TeeUp Cross
using namespace std;
int a;
string b;
int main()
{
	clearConsole();
	setForegroundColor("Cyan");
	drawRect(0,0,63,23,2,"Default","Cyan");
	drawRect(63,0,94,23,2,"Default","Cyan");
	setForegroundColor("Cyan");
	setChars(63,23,getBoxChar("TeeUp",2));
	setChars(63,0,getBoxChar("TeeDown",2));
	drawHorizontalLine(0,63,3,2,getBoxChar("TeeLeft",2),getBoxChar("TeeRight",2),"Cyan");
	setForegroundColor("White");
	setChars(64,1," Commands:");
	setChars(64,2," To move cursor:");
	setChars(64,3,"  mr = move right");
	setChars(64,4,"  ml = move left");
	setChars(64,5,"  md = move down");
	setChars(64,6,"  mu = move up");
	setChars(64,7," To set color:");
	setChars(64,8,"  sc {a}");
	setChars(64,9,"   {a} = Black, Red, Green,");
	setChars(64,10,"         Yellow, Blue, White,");
	setChars(64,11,"         Magenta, Cyan");
	setChars(64,12," To set brightness:");
	setChars(64,13,"  sb {a}");
	setChars(64,14,"   {a} = 0-3");
	setChars(43,3,"Color: ");
	setChars(43,4,"Brightness: ");
	setChars(43,5,"");
	setChars(1,1,"Welcome to a Paint program!");
	setCursor(0,25);
	setRandSeed();
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			a = randBtw(0,8);
			switch(a) {
				case 0: b = "Black"; break;
				case 1: b = "Red"; break;
				case 2: b = "Green"; break;
				case 3: b = "Yellow"; break;
				case 4: b = "Blue"; break;
				case 5: b = "Magenta"; break;
				case 6: b = "Cyan"; break;
				case 7: b = "White"; break;
			}
			setForegroundColor(b);
			a = randBtw(0,4);

			switch(a) {
				case 0: b = "█"; break;
				case 1: b = "▓"; break;
				case 2: b = "▒"; break;
				case 3: b = "░"; break;
			}
			
			setChars(j+2,i+3,b);
		}
	}	
	setCursor(0,35);
	return (0);
}
