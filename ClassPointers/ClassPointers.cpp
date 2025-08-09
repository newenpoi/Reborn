#include <iostream>

#include "Character.h"

using namespace std;

/*
* TODO : Réaliser un dernier audit.
* TODO : Utilisation de la Rule Of Five / Rule of Zero.
*/

int main()
{
    Character newen("Newen"), hans("Hans");

    newen.show();

    newen.attack(hans);

    hans.show();

    newen.switchWeapon("Heaven's Fall", 80);

	newen.show();

    return 0;
}