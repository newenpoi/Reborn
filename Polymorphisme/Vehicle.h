#pragma once
#include <iostream>
#include <vector>
#include <string>

class Vehicle
{
public:
    Vehicle(int price);

    virtual void show() const;
    virtual int nbWheels() const = 0; // Méthode virtuelle pure.
    virtual ~Vehicle(); // Le destructeur doit impérativement être virtuel en utilisant le polymorphisme.

protected:
    int m_iPrice;
    int m_iYearManufacture;
    int m_iWheels;
};

class Car : public Vehicle
{
public:
    Car(int price, int doors);

    virtual void show() const; // Inutile par défaut de déclarer virtual pour les classes filles.
    virtual int nbWheels() const;
    virtual ~Car();

private:
    int m_iDoors;
};

class Bike : public Vehicle
{
public:
    Bike(int price, double speed);

    virtual void show() const;
    virtual int nbWheels() const;
    virtual ~Bike();

private:
    double m_dSpeed;
};

class Truck : public Vehicle
{
public:
    Truck(int price, int weight);

    virtual void show() const;
    virtual int nbWheels() const;
    virtual ~Truck();

private:
    int m_iWeight;
};

class Garage
{
public:
    Garage(int size);

    std::vector<Vehicle*> getVehicles() const;

    void addVehicle(Vehicle* vehicle);
    void removeVehicle(int index);
    void show() const;

private:
    int m_iSize;
    std::vector<Vehicle*> m_pVehicles;
};
