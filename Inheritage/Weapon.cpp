#include <iostream>
#include <string>

#include "Weapon.h"

using namespace std;

Weapon::Weapon()
{
    m_sName = "Vagrant Sword";
    m_iDamage = 10;
}

Weapon::Weapon(string name, int damage) : m_sName(name), m_iDamage(damage)
{

}

string Weapon::getName() const
{
    return m_sName;
}

int Weapon::getDamage() const
{
    return m_iDamage;
}

void Weapon::switch_weapon(string new_weapon, int damage)
{
    m_sName = new_weapon;
    m_iDamage = damage;
}

void Weapon::show() const
{
    cout << "Weapon : " << m_sName << endl;
    cout << "Damage : " << m_iDamage << endl;
}