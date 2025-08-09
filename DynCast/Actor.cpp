#include <iostream>
#include <string>

#include "Actor.h"

using namespace std;

Actor::Actor() : m_bActive(0)
{

}

void Actor::callOut()
{
    cout << "Actor Call Out" << endl;
}