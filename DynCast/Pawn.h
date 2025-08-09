#pragma once

#include <string>

#include "Actor.h"

class Pawn : public Actor
{
public:

    Pawn();
    virtual void callOut() override;

private:

    int m_iHealth;
};