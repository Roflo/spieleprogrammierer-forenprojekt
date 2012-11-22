#pragma once

#ifndef PHYSICAL_OBJECT_HPP
#define PHYSICAL_OBJECT_HPP

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Collision/Shapes/b2Shape.h>

#include <vector>
#include <memory> // unique_ptr

/// This class will be used to give a object a binding to
/// a physical body
class PhysicalObject
{
public:
    /// Same as a default Constructor
    PhysicalObject()
    { }
    virtual ~PhysicalObject()
    { }

    /// Overloaded Function this is for a b2CircleShape
    void bindBody(b2Body* body)
    {
        m_body = body;
    }
    
protected:

    b2Body* m_body;
};

#endif // PHYSICAL_OBJECT_HPP
