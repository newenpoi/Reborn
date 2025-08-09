#include <iostream>
#include "Magician.h"

using namespace std;

Magician::Magician() : Character(), m_iShield(50)
{

}

Magician::Magician(string name) : Character(name), m_iShield(50)
{

}

void Magician::introduction() const
{
    cout << "I'm " << m_sName << " the great magician." << endl;
}