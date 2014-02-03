#pragma once

#ifndef GRAPHICAL_OBJECT_HPP
#define GRAPHICAL_OBJECT_HPP

#include "../animation/Animation.hpp"
#include "AnimatedGraphics.hpp"
#include "Drawable.hpp"

#include <memory>
#include <vector>

/// This class defines typical behavior of graphical objects
class GraphicalObject : public Drawable
{
private:

    std::vector<std::unique_ptr<Animation>> m_animations;
    bool m_hide;

public:

    GraphicalObject() : m_hide(false)
    {
    }

    void hide()
    {
        m_hide = true;
    }

    void unhide()
    {
        m_hide = false;
    }

    bool hidden() const
    {
        return m_hide;
    }

    virtual void draw(const DrawParameter& param)
    {
        if(m_hide)
            return;

        for(auto animation = begin(m_animations); animation != end(m_animations); ++animation)
            if((*animation) != nullptr && !(*animation)->isStopped())
                (*animation)->draw(param);
    }

    void bindAnimation(std::unique_ptr<Animation> animation)
    {
        m_animations.push_back(std::move(animation));
    }

protected:
    const std::vector<std::unique_ptr<Animation>>& getAnimations() const
    {
        return m_animations;
    }
};

#endif // GRAPHICAL_OBJECT_HPP
