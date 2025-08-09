#include "Pointer.h"

#include <iostream>
using namespace std;

int Pointer::execute()
{
    int age(16);
    int* pointer(0);

    pointer = &age;

    cout << &age << endl;
    cout << pointer << endl;

    cout << *pointer << endl;

    // Pas de d�f�rencement ici car l'�ge n'a jamais �t� allou� dynamiquement avec new.
    // delete pointer;
    // pointer = 0;

    return 0;
}