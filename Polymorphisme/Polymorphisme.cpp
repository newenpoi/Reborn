// Polymorphisme.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
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

void introduction(Vehicle const& v)
{
    v.show();
}

int main()
{
	// Créé un vecteur de pointeurs vers des véhicules.
    vector<Vehicle*> vehicles;

	// Ajoute différents types de véhicules.
    vehicles.push_back(new Car(16000, 5));
    vehicles.push_back(new Car(32000, 3));
    vehicles.push_back(new Bike(4000, 320));

	// Affiche les informations de chaque véhicule.
    vehicles[0]->show();
    vehicles[1]->show();
    vehicles[2]->show();

    // Libérer la mémoire.
    for (int i(0); i < vehicles.size(); ++i)
    {
        // Supprime le véhicule (libère la mémoire) à l'indice i.
        delete vehicles[i];
        
		// Met à jour le pointeur pour éviter de pointer vers une adresse invalide.
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

    Car fuckingCar(18000, 3);

    ptr = &fuckingCar;

    cout << ptr->nbWheels() << endl;

    return 0;
}