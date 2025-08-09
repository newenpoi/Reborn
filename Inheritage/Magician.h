#pragma once

#include <iostream>
#include <string>

#include "Character.h"

class Magician : public Character
{
public:

    Magician();
    Magician(std::string name);

    void introduction() const;

private:

    int m_iShield; // Valeur du bouclier magique.
};