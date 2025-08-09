#pragma once

#include <string>

#include "Weapon.h"
#include "Pawn.h"

class Character : public Pawn
{
public:

    Character();
    Character(Character const& copy); // Une référence constante vers un objet du même type (constructeur de copie).
    Character(const std::string& name);
    Character(const std::string& weapon_name, int weapon_damage);
    ~Character();

    /*
        La surcharge et le constructeur de copie vont de paire.
    */

    Character& operator=(Character const& other);

    void receiveDamage(int damage);
    void attack(Character& target);
    void heal(int amount);
    void switchWeapon(const std::string& new_weapon, int damage);
    void show() const;
    bool is_alive() const;
    virtual void callOut() override;

private:

    int m_iHealth;
    int m_iMana;
    std::unique_ptr<Weapon> m_eWeapon;
    std::string m_sName;
};