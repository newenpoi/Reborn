#pragma once

#include <iostream>
#include <string>

#include "Character.h"

class Warrior : public Character
{
public:

    Warrior();
    Warrior(std::string name);

    void introduction() const;

private:

    int m_iRage; // Niveau de rage.
};