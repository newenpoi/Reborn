#pragma once

#include <iostream>

class Polygone
{
public:
    constexpr Polygone() = default;

    // M�thode virtuelle.
    virtual void afficher() const;

    // M�thode Virtuelle Pure.
    virtual int nbVertices() const = 0;

protected:
    // Initialisation directe.
    int m_iVertices{0};
};

class Triangle : public Polygone
{
public:
    Triangle() {};

    // Par d�faut il est inutile de red�clarer le mot cl� virtual pour les classes filles.
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