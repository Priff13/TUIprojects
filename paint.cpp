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
int cursorX = 0;
int cursorY = 0;
string b;
int brightness[20][40];
int cols[20][40];
int currentBrightness = 0;
int currentColor = 1;
int bound(int min, int x, int max) {
	if (x < min) {x = min;}
	if (x > max) {x = max;}
	return(x);
}
string getColor(int col) 
{
	string b;
	switch(col) {
		case 0: b = "Black"; break;
		case 1: b = "Red"; break;
		case 2: b = "Green"; break;
		case 3: b = "Yellow"; break;
		case 4: b = "Blue"; break;
		case 5: b = "Magenta"; break;
		case 6: b = "Cyan"; break;
		case 7: b = "White"; break;
	}
	return(b);
}
int getColorReverse(string color) {
	int a;
	if (color == "Black")
    {
        a = 0;
    }
    if (color == "Red")
    {
        a = 1;
    }
    if (color == "Green")
    {
        a = 2;
    }
    if (color == "Yellow")
    {
        a = 3;
    }
    if (color == "Blue")
    {
        a = 4;
    }
    if (color == "Magenta")
    {
        a = 5;
    }
    if (color == "Cyan")
    {
        a = 6;
    }
    if (color == "White")
    {
        a = 7;
    }
	return(a);
}
string getBrightness(int brt)
{
	string b;
	switch(brt) {
		case 0: b = "█"; break;
		case 1: b = "▓"; break;
		case 2: b = "▒"; break;
		case 3: b = "░"; break;
	}
	return(b);
}
void drawVars() {
	setForegroundColor(getColor(currentColor));
	setChars(60,5,getBrightness(currentBrightness));
	clearColors();
	setChars(55,4,to_string(currentBrightness));
	setChars(50,3,getColor(currentColor));
	setCursor(0,25);
}
int main()
{
	//text + ANSI boxes
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
	setChars(64,2,"  To move cursor:");
	setChars(64,3,"   use the arrow keys.");
	setChars(64,4,"  To set color:");
	setChars(64,5,"   sc {a}");
	setChars(64,6,"    {a} = Black, Red,");
	setChars(64,7,"          Green, Yellow,");
	setChars(64,8,"          Blue, White,");
	setChars(64,9,"          Magenta, Cyan");
	setChars(64,10,"  To set brightness:");
	setChars(64,11,"   sb {a}");
	setChars(64,12,"    {a} = 0-3");
	setChars(64,13,"  To paint a square:");
	setChars(64,14,"   paint");
	setChars(64,15,"  To paint everything:");
	setChars(64,16,"   fill");
	setChars(43,3,"Color: ");
	setChars(43,4,"Brightness: ");
	setChars(43,5,"Current setting: ");
	setChars(1,1," Welcome to a Paint program!");
	setRandSeed(); //just in case
	for (int i = 0; i < 20; i++) { //makes everything pure white
		for (int j = 0; j < 40; j++) {
			setForegroundColor("White");
			cols[i][j] = 7;
			brightness[i][j] = 0;
			setChars(j+2,i+3,"█");
		}
	}	

	drawVars(); 
	string input;
	while (input != "exit") { //repeats until the input = "exit"
		getline(cin,input); //get input
		a = cols[cursorY][bound(0,cursorX-1,40)]; //set a to color at cursorX,cursorY
		b = getColor(a); 
		setForegroundColor(b);
		a = brightness[cursorY][bound(0,cursorX-1,40)]; //set a to brightness at cursorX,cursorY
		b = getBrightness(a);
		if (cursorX > 0) {
			setChars(cursorX+1,cursorY+3,b); //draw remove X at cursor from previous cycle
		}
		if (input == "\x1b[A") { //UP arrow key
			if (cursorY > 0) {
				cursorY--;
			}
		}	
		if (input == "\x1b[B") { //DOWN arrow key
			if (cursorY < 20) {
				cursorY++;
			}
		}
		if (input == "\x1b[D") { //LEFT arrow key
			if (cursorX > 0) {
				cursorX--;
			}
		}
		if (input == "\x1b[C") { //RIGHT arrow key
			if (cursorX < 40) {
				cursorX++;
			}
		}
		if (input == "paint") { //set Color and Brightness at Cursor pos. to current
			cols[cursorY][bound(0,cursorX-1,40)] = currentColor;
			brightness[cursorY][bound(0,cursorX-1,40)] = currentBrightness;
		}
		if (input.substr(0,2) == "sb") { //sets current brightness
			char b = input[3];
			int a;
			if(b=='0'){a=0;}if(b=='1'){a=1;}if(b=='2'){a=2;}if(b=='3'){a=3;} //had to include this cuz c++ sucks
			currentBrightness = a; 
		}
		if (input.substr(0,2) == "sc") { //sets current color
			currentColor = getColorReverse(input.substr(3,input.length()));
		}
		if (input == "fill") {
			for (int i = 0; i < 20; i++) { //fills everything with current color
				for (int j = 0; j < 40; j++) {
					setForegroundColor(getColor(currentColor));
					cols[i][j] = currentColor;
					brightness[i][j] = currentBrightness;
					setChars(j+2,i+3,getBrightness(currentBrightness));
				}
			}	
		}
		clearColors();
		setChars(cursorX+1,cursorY+3,"X"); //draw X where cursor is positioned
		//fill command
		drawVars();
		cout << "\x1b[2K\r"; //clear input line
	}
	return (0);
}
