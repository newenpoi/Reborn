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
    
	// Peut être supprimé avec unique_ptr.
    ~Character();

    /*
        La surcharge et le constructeur de copie (plus haut) vont de paire.
    */

    Character& operator=(Character const& other);

    void receiveDamage(int damage);
    void attack(Character& target);
    void heal(int amount);
    void switchWeapon(std::string new_weapon, int damage);
    void show() const;
    bool is_alive() const;

private:

    int m_iHealth;
    int m_iMana;
    
    /*
	* Weapon *m_eWeapon (style C++ 98) devient désormais unique_ptr<Weapon> m_eWeapon.
    */
    
    std::unique_ptr<Weapon> m_eWeapon;
    
    
    std::string m_sName;
};