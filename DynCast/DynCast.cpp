// DynCast.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Actor.h"
#include "Pawn.h"
#include "Character.h"

using namespace std;

/*
* Le code principal démontre l'utilisation du dynamic_cast en tentant de convertir des pointeurs Actor vers des types dérivés (Actor, Pawn, Character) et d'appeler leurs méthodes spécifiques.
* La « distribution dynamique » est utilisée pour vérifier si la conversion est possible, et si oui, la méthode callOut() correspondante est appelée.
*/

int main()
{
    Actor* a = new Actor;
    Actor* p = new Pawn;
    Actor* c = new Character;

    Actor* ObjectArray[3];
    ObjectArray[0] = a;
    ObjectArray[1] = p;
    ObjectArray[2] = c;

    for (int i = 0; i < 3; i++)
    {
        cout << i << endl;

        Actor* A = dynamic_cast<Actor*>(ObjectArray[i]);
        if (A) A->callOut();

        Pawn* P = dynamic_cast<Pawn*>(ObjectArray[i]);
        if (P) P->callOut();

        Character* C = dynamic_cast<Character*>(ObjectArray[i]);
        if (C) C->callOut();
    }

    return 0;
}