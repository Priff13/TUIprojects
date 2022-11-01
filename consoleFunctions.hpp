#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
// Colors: Black Red Green Yellow Blue Magenta Cyan White
// Box Chars: Hori Very ElbowBR ElbowBL ElbowTR ElbowTL TeeRight TeeLeft TeeDown TeeUp Cross
std::string characters[44] = { "─", "│", "┌", "┐", "└", "┘", "├", "┤", "┬", "┴", "┼", "━", "┃", "┏", "┓", "┗", "┛", "┣", "┫", "┳", "┻", "╋", "═", "║", "╔", "╗", "╚", "╝", "╠", "╣", "╦", "╩", "╬", "─", "│", "╭", "╮", "╰", "╯", "├", "┤", "┬", "┴", "┼"};
int randBtw(int a, int b)
{
    return ((std::rand() % (b - a)) + a);
}
void setRandSeed() {
    std::srand(std::time(NULL));
}
std::string getBoxChar(std::string name, int type)
{
    int a = 0;
    if (name == "Hori")
    {
        a = 0;
    }
    if (name == "Vert")
    {
        a = 1;
    }
    if (name == "ElbowBR")
    {
        a = 2;
    }
    if (name == "ElbowBL")
    {
        a = 3;
    }
    if (name == "ElbowTR")
    {
        a = 4;
    }
    if (name == "ElbowTL")
    {
        a = 5;
    }
    if (name == "TeeRight")
    {
        a = 6;
    }
    if (name == "TeeLeft")
    {
        a = 7;
    }
    if (name == "TeeDown")
    {
        a = 8;
    }
    if (name == "TeeUp")
    {
        a = 9;
    }
    if (name == "Cross")
    {
        a = 11;
    }
    return (characters[(type * 11) + a]);
}
void setForegroundColor(std::string color)
{
    int a;
    if (color == "Black")
    {
        a = 30;
    }
    if (color == "Red")
    {
        a = 31;
    }
    if (color == "Green")
    {
        a = 32;
    }
    if (color == "Yellow")
    {
        a = 33;
    }
    if (color == "Blue")
    {
        a = 34;
    }
    if (color == "Magenta")
    {
        a = 35;
    }
    if (color == "Cyan")
    {
        a = 36;
    }
    if (color == "White")
    {
        a = 37;
    }
    std::cout << "\x1b[" << a << "m" << std::flush;
}
void setBackgroundColor(std::string color)
{
    int a;
    if (color == "Black")
    {
        a = 40;
    }
    if (color == "Red")
    {
        a = 41;
    }
    if (color == "Green")
    {
        a = 42;
    }
    if (color == "Yellow")
    {
        a = 43;
    }
    if (color == "Blue")
    {
        a = 44;
    }
    if (color == "Magenta")
    {
        a = 45;
    }
    if (color == "Cyan")
    {
        a = 46;
    }
    if (color == "White")
    {
        a = 47;
    }
    std::cout << "\x1b[" << a << "m" << std::flush;
}
void clearConsole()
{
    std::cout << "\x1B[2J\x1B[H" << std::flush;
}
void setCursor(int y, int x)
{
    std::cout << "\x1b[" << x << ";" << y << "f" << std::flush;
}
void setChars(int x, int y, std::string thing)
{
    x++;y++;
    setCursor(x, y);
    std::cout << thing;
    std::cout << "\x1b[H" << std::flush;
}
void resetCursor()
{
    std::cout << "\x1b[H" << std::flush;
}
void clearColors()
{
    std::cout << "\x1b[0m" << std::flush;
}
void moveCursor(int lr, int ud)
{
    if (lr < 0)
    {
        lr = abs(lr);
        std::cout << "\x1b[" << lr << "D";
    }
    if (lr > 0)
    {
        std::cout << "\x1b[" << lr << "C";
    }
    if (ud < 0)
    {
        ud = abs(ud);
        std::cout << "\x1b[" << ud << "B";
    }
    if (ud > 0)
    {
        std::cout << "\x1b[" << ud << "A";
    }
    std::cerr << "";
}
void drawRect(int x, int y, int x0, int y0, int type, std::string backgroundColor = "Default", std::string textColor = "Default")
{
    y--;
    setCursor(x, y);
    if (backgroundColor != "Default")
    {
        setBackgroundColor(backgroundColor);
    }
    if (textColor != "Default")
    {
        setForegroundColor(textColor);
    }
    setChars(x, y, getBoxChar("ElbowBR",type));
    int i = x + 1;
    int j = y;
    j++;
    while (i < x0)
    {
        setChars(i, j, getBoxChar("Hori",type));
        i++;
    }
    setChars(i, j, getBoxChar("ElbowBL",type));
    j++;
    while (j < y0)
    {
        setChars(i, j, getBoxChar("Vert",type));
        j++;
    }
    setChars(i, j, getBoxChar("ElbowTL",type));
    i--;
    while (i > x)
    {
        setChars(i, j, getBoxChar("Hori",type));
        i--;
    }
    setChars(i, j, getBoxChar("ElbowTR",type));
    j--;
    while (j > y + 1)
    {
        setChars(i, j, getBoxChar("Vert",type));
        j--;
    }
    std::cout << "\x1b[0m" << std::flush;
    std::cerr << "";
}
void drawVerticalLine(int y, int y0, int x, int type, std::string edgeBottomChar = "Hori", std::string edgeTopChar = "Hori", std::string textColor = "Default")
{
    setForegroundColor(textColor);
    for (int i = y; i < y0; i++) {
        setChars(x,i,getBoxChar("Hori",type));
    }
    if (edgeTopChar != "Hori") {
        setChars(x,y,edgeTopChar);
    }
    if (edgeBottomChar != "Hori") {
        setChars(x,y0,edgeBottomChar);
    }
}
void drawHorizontalLine(int x, int x0, int y, int type, std::string edgeRightChar = "Hori", std::string edgeLeftChar = "Hori", std::string textColor = "Default")
{
    y--;
    setForegroundColor(textColor);
    for (int i = x; i < x0; i++) {
        setChars(i,y,getBoxChar("Hori",type));
    }
    if (edgeLeftChar != "Hori") {
        setChars(x,y,edgeLeftChar);
    }
    if (edgeRightChar != "Hori") {
        setChars(x0,y,edgeRightChar);
    }
}

void scroll(int lines)
{
    std::cout << "\x1b[r";
    if (lines < 0)
    {
        for (int i = 0; i < lines; i++)
        {
            std::cout << "\x1b[D";
        }
    }
    else
    {
        lines = abs(lines);
        for (int i = 0; i < lines; i++)
        {
            std::cout << "\x1b[D";
        }
    }
    std::cerr << "";
}