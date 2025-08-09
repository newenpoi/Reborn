#include <iostream>

#include "Time.h"

using namespace std;

/*
* Ce projet illustre l'utilisation de la surcharge d'opérateurs en C++.
* Il permet de manipuler des durées (heures, minutes, secondes) et de les additionner de manière intuitive.
* La classe Time permet de créer des objets représentant des durées, de les comparer et/ou de les additionner.
*/

int main()
{
    Time a(5400), b(1800), c(3600);

    a.show();
    b.show();

    // Équivalent de resultat = operator+(operator+(temps_a, temps_b), temps_c);
    Time d = a + 30;

    d.show();

    return 0;
}