
/*
* Refontes 2025 :
* 1. Remplacer toutes les initialisations de m_eWeapon(0) par m_eWeapon(nullptr) ou mieux, initialiser avec std::make_unique<Weapon>().
* 2. Adapter les constructeurs pour utiliser std::make_unique<Weapon> au lieu de new Weapon.
* 3. Supprimer les delete m_eWeapon; car unique_ptr gère la destruction automatiquement.
* 4. Adapter l'opérateur d'affectation pour utiliser std::make_unique<Weapon>.
*/

#include <iostream>
#include <string>
#include <memory>
#include "Character.h"

using namespace std;

Character::Character() : m_iHealth(100), m_iMana(100), m_eWeapon(std::make_unique<Weapon>())
{
}

Character::Character(Character const& copy) : m_iHealth(copy.m_iHealth), m_iMana(copy.m_iMana), m_eWeapon(std::make_unique<Weapon>(*(copy.m_eWeapon)))
{
}

Character::Character(string weapon_name, int weapon_damage) : m_iHealth(100), m_iMana(100), m_eWeapon(std::make_unique<Weapon>(weapon_name, weapon_damage))
{
}

Character::Character(string name) : m_sName(name), m_iHealth(100), m_iMana(100), m_eWeapon(std::make_unique<Weapon>())
{
}

/*
* Le destructeur n'a pas besoin de faire quoi que ce soit car unique_ptr gère la destruction automatiquement.
*/
Character::~Character() {}

Character& Character::operator=(Character const& other)
{
    if (this != &other)
    {
        m_iHealth = other.m_iHealth;
        m_iMana = other.m_iMana;
        m_sName = other.m_sName;
        m_eWeapon = std::make_unique<Weapon>(*(other.m_eWeapon));
    }
    return *this;
}

void Character::receiveDamage(int damage)
{
    m_iHealth -= damage;
    if (m_iHealth < 0)
    {
        m_iHealth = 0;
    }
}

void Character::attack(Character& target)
{
    target.receiveDamage(m_eWeapon->getDamage());
}

void Character::heal(int amount)
{
    m_iHealth += amount;
    if (m_iHealth > 100)
    {
        m_iHealth = 100;
    }
}

void Character::switchWeapon(string new_weapon_name, int damage)
{
    m_eWeapon = std::make_unique<Weapon>(new_weapon_name, damage);
    cout << "Nouvelle Arme Équipée : " << new_weapon_name << endl;
}

void Character::show() const
{
    cout << "Sobriquet : " << m_sName << endl;
    cout << "HP : " << m_iHealth << endl;
    cout << "MP : " << m_iMana << endl;
    m_eWeapon->show();
}

bool Character::is_alive() const
{
    return m_iHealth > 0;
}