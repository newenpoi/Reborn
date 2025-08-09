#include <iostream>
#include "Warrior.h"

using namespace std;

Warrior::Warrior() : Character(), m_iRage(0)
{

}

Warrior::Warrior(string name) : Character(name), m_iRage(0)
{

}

void Warrior::introduction() const
{
    cout << "I'm " << m_sName << " a powerful warrior!" << endl;
}