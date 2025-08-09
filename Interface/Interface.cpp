// Interface.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

#include "Polygon.h"

using namespace std;

int main()
{
    Triangle abc;
    Quad abcd;

    abc.afficher();
    abcd.afficher();

    /*
	*   Premiers concepts en Polymorphisme.
        On ne pourra pas faire Polygone p mais on peut :
    */

    Polygone* ptr(0);

    Triangle triangle;
    
	// Le pointeur pointe maintenant vers un objet Triangle (upcasting).
    ptr = &triangle;

    ptr->afficher();
    cout << ptr->nbVertices() << endl;

    return 0;
}