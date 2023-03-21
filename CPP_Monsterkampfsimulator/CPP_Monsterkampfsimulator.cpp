#include <iostream>
#include "Monster.h"
#include "CPP_Monsterkampfsimulator.h"
using namespace std;
int main(int argc, char* argv[])
{
    std::cout << "Hallo Andre" << std::endl;
    cout << "so geht's auch!"<< endl;

    cout << "type something and I will repeat: ";
    char sz[256];
    cin >> sz; //>> is the extraction operator, << is the insertion operator
    cout << "You typed: " << sz << endl; //repeats only the first word

    cout << "type something and I will repeat: ";
    cin.getline(sz, 256); //cin.getline() reads a whole line
    cout << "You typed: " << sz << endl; //repeats the whole line

    Monster obj1{};
    printf("Monster Health: %d", obj1.monsterHealth);
    obj1.monsterHealth = 50;
    printf("Monster Health: %d", obj1.monsterHealth);
    return 0;
}
