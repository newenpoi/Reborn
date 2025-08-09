#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

Character::Character() : m_iHealth(100), m_iMana(100), m_eWeapon(std::make_unique<Weapon>())
{
}

Character::Character(Character const& copy) : m_iHealth(copy.m_iHealth), m_iMana(copy.m_iMana), m_eWeapon(std::make_unique<Weapon>(*(copy.m_eWeapon)))
{
}

Character::Character(const string& weapon_name, int weapon_damage) : m_iHealth(100), m_iMana(100), m_eWeapon(std::make_unique<Weapon>(weapon_name, weapon_damage))
{
}

Character::Character(const string& name) : m_sName(name), m_iHealth(100), m_iMana(100), m_eWeapon(std::make_unique<Weapon>())
{
}

Character::~Character()
{
}

Character& Character::operator=(Character const& other)
{
    // Vérifie que l'objet n'est pas le même que celui en argument (deux adresses distinctes).
    if (this != &other)
    {
        m_iHealth = other.m_iHealth;
        m_iMana = other.m_iMana;

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

void Character::switchWeapon(const string& new_weapon_name, int damage)
{
    m_eWeapon = std::make_unique<Weapon>(new_weapon_name, damage);
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
    // Renvoie true si m_iHealth > 0 sinon false.
    return m_iHealth > 0;
}

void Character::callOut()
{
    cout << "Character Call Out" << endl;
}