#include <iostream>
#include "Character.h"

using namespace std;

Character::Character() : m_iHealth(100), m_iMana(100), m_eWeapon(0)
{
    m_eWeapon = new Weapon();
}

Character::Character(string name) : m_sName(name), m_iHealth(100), m_iMana(100), m_eWeapon(0)
{

}

Character::Character(Character const& copy) : m_iHealth(copy.m_iHealth), m_iMana(copy.m_iMana), m_eWeapon(0)
{
    // On envoi l'objet lui même et pas son adresse.
    m_eWeapon = new Weapon(*(copy.m_eWeapon));
}

Character::Character(string weapon_name, int weapon_damage) : m_iHealth(100), m_iMana(100), m_eWeapon(0)
{
    m_eWeapon = new Weapon(weapon_name, weapon_damage);
}

Character::~Character()
{
    /*
        S'assurer de libérer la mémoire (allocation dynamique).
    */

    delete m_eWeapon;
}

Character& Character::operator=(Character const& other)
{
    // Vérifie que l'objet n'est pas le même que celui en argument (deux adresses distinctes).
    if (this != &other)
    {
        m_iHealth = other.m_iHealth;
        m_iMana = other.m_iMana;

        delete m_eWeapon;

        m_eWeapon = new Weapon(*(other.m_eWeapon));
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

void Character::fist(Character& target) const
{
    /*
        Il s'agit d'une attaque de type coup de poing et non d'un fist-fucking.
    */

    target.receiveDamage(10);
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
    m_eWeapon->switch_weapon(new_weapon_name, damage);
}

void Character::introduction() const
{
    cout << "I'm " << m_sName << " and just a mere human." << endl;
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