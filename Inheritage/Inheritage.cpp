// Inheritage.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>

#include "Character.h"
#include "Warrior.h"
#include "Magician.h"

using namespace std;

int main()
{
    Character newen("Newen"), * other_character(0);
    Warrior hans("Hans");

    Magician* nanana = new Magician("Nanana");

    other_character = nanana;

    newen.fist(hans);

    newen.introduction();
    hans.introduction();

    nanana->introduction();
    other_character->introduction(); // Pour comprendre le principe.

    return 0;
}