#include "Pointing.h"

#include <iostream>
using namespace std;

int Pointing::execute()
{
    /*
        TODO :
        Notre pointeur doit allouer sa m�moire afin de pouvoir y stocker des donn�es.
        d'o� pointer = new int;
        Sans �a, notre programme s'arr�tera de mani�re innatendue.
    */

    int* pointer(0);
    pointer = new int;

    cout << "Please enter your age : ";
    cin >> *pointer;

    cout << "Your age is : " << *pointer << "." << endl;

    cout << "Your age is stored at the address : " << pointer << endl;

    // D�f�rencement.
    delete pointer;
    pointer = 0;

    return 0;
}