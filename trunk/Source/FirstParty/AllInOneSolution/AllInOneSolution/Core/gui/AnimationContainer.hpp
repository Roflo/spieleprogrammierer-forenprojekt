#pragma once

#ifndef ANIMATIONCONTAINER_HPP
#define ANIMATIONCONTAINER_HPP

#include "../model/AnimatedGraphics.hpp"
#include "MenuElement.hpp"

class AnimationContainer : public AnimatedGraphics, public MenuElement
{
private:
    std::map<std::string, float> m_variables;
    Animation* m_updatingAni;
public:
    AnimationContainer();

    virtual float getValueOf(const std::string& name) const override;
    virtual void setValueOf(const std::string& name, const float value) override;
    virtual void update(const sf::RenderWindow& screen, const sf::Vector2i& mouseOffset = sf::Vector2i(0, 0)) override;
};

#endif