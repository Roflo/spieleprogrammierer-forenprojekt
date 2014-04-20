#pragma once

#ifndef ANIMATIONCONTAINER_HPP
#define ANIMATIONCONTAINER_HPP

#include "../model/AnimatedGraphics.hpp"
#include "MenuElement.hpp"

class AnimationContainer : public virtual AnimatedGraphics, public virtual MenuElement
{
private:
    std::map<std::string, float> m_variables;
    Animation* m_updatingAni;
public:
    AnimationContainer(const sf::Vector2f& position, int id);
    AnimationContainer(AnimationContainer&& toMove);

    virtual float getValueOf(const std::string& name) const override;
    virtual void setValueOf(const std::string& name, const float value) override;
    virtual void update(const sf::RenderWindow& screen, const float time, const sf::Vector2i& mouseOffset = sf::Vector2i(0, 0)) override;
    virtual void draw(const DrawParameter& param) override;
};

#endif