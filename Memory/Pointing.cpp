#include "Pointing.h"

#include <iostream>
using namespace std;

int Pointing::execute()
{
    /*
        TODO :
        Notre pointeur doit allouer sa mémoire afin de pouvoir y stocker des données.
        d'où pointer = new int;
        Sans ça, notre programme s'arrêtera de manière innatendue.
    */

    int* pointer(0);
    pointer = new int;

    cout << "Please enter your age : ";
    cin >> *pointer;

    cout << "Your age is : " << *pointer << "." << endl;

    cout << "Your age is stored at the address : " << pointer << endl;

    // Déférencement.
    delete pointer;
    pointer = 0;

    return 0;
}