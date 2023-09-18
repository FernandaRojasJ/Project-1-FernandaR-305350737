
#include <iostream>
#include<SFML/Graphics.hpp>
#include"WindowGraphic.h"
#include <Windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    WindowGraphic game = WindowGraphic();
    game.run();
}


