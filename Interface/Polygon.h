#pragma once

#include <iostream>

class Polygone
{
public:
    constexpr Polygone() = default;

    // Méthode virtuelle.
    virtual void afficher() const;

    // Méthode Virtuelle Pure.
    virtual int nbVertices() const = 0;

protected:
    // Initialisation directe.
    int m_iVertices{0};
};

class Triangle : public Polygone
{
public:
    Triangle() {};

    // Par défaut il est inutile de redéclarer le mot clé virtual pour les classes filles.
    virtual void afficher() const;
    // Idem.
    virtual int nbVertices() const;
};

class Quad : public Polygone
{
public:
    Quad() {};

    virtual void afficher() const;
    virtual int nbVertices() const;
};

class Pentagone : public Polygone
{
public:
    Pentagone() {};

    virtual void afficher() const;
    virtual int nbVertices() const;
};