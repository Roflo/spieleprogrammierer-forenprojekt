#pragma once

#ifndef NEVER_HPP
#define NEVER_HPP

#include "CollisionFilter.hpp"

class Never : public CollisionFilter
{
public:

    virtual bool shouldCollide(Entity* entityA, Entity* entityB)
    {
        return false;
    }
};

#endif // COLLISION_FILTER_HPP