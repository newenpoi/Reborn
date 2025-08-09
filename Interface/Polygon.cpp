#include "Polygon.h"

using namespace std;

void Polygone::afficher() const
{
    cout << u8"Je suis un polygone, c'est s�r, c'est certain m�me." << endl;
}

/*
    Triangle
*/

void Triangle::afficher() const
{
    cout << u8"Je suis un triangle mais aussi un polygone." << endl;
}

int Triangle::nbVertices() const
{
    return 3;
}

/*
    Quadrilat�re
*/

void Quad::afficher() const
{
    cout << u8"Je suis un quadrilatere mais aussi un polygone." << endl;
}

/*
    Pentagone
*/

void Pentagone::afficher() const
{
    cout << u8"Je suis un pentagone mais aussi un polygone." << endl;
}

int Pentagone::nbVertices() const
{
    return 5;
}