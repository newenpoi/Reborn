#include <iostream>
#include <string>

#include "Vehicle.h"

using namespace std;

/*
    Constructeurs - Surchages / Destructeurs
*/

Vehicle::Vehicle(int price) : m_iPrice(price)
{

}

Vehicle::~Vehicle()
{
    cout << "Object deleted." << endl;
}

Car::Car(int price, int doors) : Vehicle(price), m_iDoors(doors)
{

}

Car::~Car()
{

}

Bike::Bike(int price, double speed) : Vehicle(price), m_dSpeed(speed)
{

}

Bike::~Bike()
{

}

Truck::Truck(int price, int weight) : Vehicle(price), m_iWeight(weight)
{

}

Truck::~Truck()
{

}

Garage::Garage(int size) : m_iSize(size)
{

}

/*
    Les méthodes show() ont un comportement polymorphique.
*/

void Vehicle::show() const
{
    cout << "I'm a vehicle." << endl;
}

void Car::show() const
{
    cout << "I'm certainly a car." << endl;
}

void Bike::show() const
{
    cout << "I'm a fucking bike." << endl;
}

void Truck::show() const
{
    cout << "I'm a truck not a tuc !" << endl;
}

/*
    Fonction Virtuelles / Virtuelles Pures
*/

int Car::nbWheels() const
{
    return 4;
}

int Bike::nbWheels() const
{
    return 2;
}

int Truck::nbWheels() const
{
    return 4;
}

/*
    Garage
*/

vector<Vehicle*> Garage::getVehicles() const
{
    return m_pVehicles;
}

void Garage::addVehicle(Vehicle* vehicle)
{
    m_pVehicles.push_back(vehicle);
}

void Garage::removeVehicle(int index)
{
    /*
        La gestion des pointeurs reste la responsabilité de l'utilisateur.
    */

	// Libère la mémoire allouée pour le véhicule à l'index spécifié.
    delete m_pVehicles[index];

    // Puis supprime le pointeur invalide de la liste.
    m_pVehicles.erase(m_pVehicles.begin() + index);
}

void Garage::show() const
{
    for (int i(0); i < m_pVehicles.size(); ++i)
    {
        m_pVehicles[i]->show();
    }
}