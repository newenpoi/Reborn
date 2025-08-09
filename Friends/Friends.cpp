// Friends.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

#include "Vehicle.h"

using namespace std;

/*
    Un même morceau de code aura deux comportements différents suivant le type passé en argument.
    C'est du polymorphisme.
*/

/*
    On y retrouvera des fonctions virtuelles et une fonction virtuelle pure.
    On parle également du principe d'abstraction.
    + Utilisation de collections hétérogènes.
*/

int main()
{
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Car(16000, 5));

    vehicles.push_back(new Car(32000, 3));

    vehicles.push_back(new Bike(4000, 320));

    vehicles[0]->show();
    vehicles[1]->show();
    vehicles[2]->show();

    // Libérer la mémoire.

    for (int i(0); i < vehicles.size(); ++i)
    {
        delete vehicles[i];
        vehicles[i] = 0;
    }

    // Exemple II :
    // Création d'un garage avec quatre places disponibles.
    // Disons le garage Midas ? LOL.
    Garage midas(4);

    midas.addVehicle(new Car(12000, 5));
    midas.addVehicle(new Bike(8000, 380));
    midas.addVehicle(new Truck(15000, 3));

    midas.removeVehicle(1);

    midas.show();

    /*
        Juste pour illustrer un peu plus l'abstraction.
        On ne pourra pas faire Vehicle v(price) mais on peut :
    */

    Vehicle* ptr(0);

    Car fuckingCar(18000, 3), other_car(3000, 3);

    ptr = &fuckingCar;

    Vehicle::introduction(other_car);

    cout << ptr->nbWheels() << endl;

    return 0;
}