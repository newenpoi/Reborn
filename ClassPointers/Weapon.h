#pragma once

#include <string>

class Weapon
{
public:

    Weapon();
    Weapon(std::string name, int damage);

    std::string getName() const;
    int getDamage() const;

    void switch_weapon(std::string name, int damage);
    void show() const;

private:

    std::string m_sName;
    int m_iDamage;
};

