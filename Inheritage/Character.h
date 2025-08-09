#pragma once

#include <string>
#include "Weapon.h"

class Character
{
public:

    Character();
    Character(Character const& copy); // Une référence constante vers un objet du même type (constructeur de copie).
    Character(std::string name);
    Character(std::string weapon_name, int weapon_damage);
    ~Character();

    Character& operator=(Character const& other); // Surcharge d'opérateur d'égalité de Personnage.

    void receiveDamage(int damage);
    void fist(Character& target) const; // Attaque coup de poing vers la cible.
    void heal(int amount);
    void switchWeapon(std::string new_weapon, int damage);
    void introduction() const;
    void show() const;
    bool is_alive() const;

protected:

    int m_iHealth;
    int m_iMana;
    Weapon* m_eWeapon;
    std::string m_sName;
};