#include <iostream>
#include <windows.h>
#include "CPP_Monsterkampfsimulator.h"
#include "Monster.h"
#include "StringifierClass.h"
#include "MainMenu.h"
using namespace std;
int main(int argc, char* argv[])
{
    HWND console = GetConsoleWindow();
    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    SetWindowPos(console, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
    ShowWindow(console, SW_MAXIMIZE);
    // initilatation of objects for the game
    MainMenu menuObj;
    StringifierClass strings{};
    Monster obj1{1};

    menuObj.StartMenu();
    //cout << obj1._monsterRace<< "\n"<< "Life:" << strings.HealthString(obj1.GetMaxHealth(), obj1.GetHealth()) << endl;
    

    return 0;
}









    //printf("Monster Health: %s", obj1.HealthDisplay());
    //std::cout << "Hallo Andre" << std::endl;
    //cout << "so geht's auch!"<< endl;

    //cout << "type something and I will repeat: ";
    //char sz[256];
    //cin >> sz; //>> is the extraction operator, << is the insertion operator
    //cout << "You typed: " << sz << endl; //repeats only the first word

    //cout << "type something and I will repeat: ";
    //cin.getline(sz, 256); //cin.getline() reads a whole line
    //cout << "You typed: " << sz << endl; //repeats the whole line