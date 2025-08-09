#pragma once

#include <string>

class Actor
{
public:

    Actor();
    virtual void callOut();

private:

    bool m_bActive;
};