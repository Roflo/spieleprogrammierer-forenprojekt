#pragma once

#ifndef VERTICALSLIDINGSTRIPES_TRANSITION_HPP
#define VERTICALSLIDINGSTRIPES_TRANSITION_HPP

#include "Transition.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>

class VerticalSlidingStripesTransition : public Transition
{
public:
    
    VerticalSlidingStripesTransition(
        const sf::Texture* sourceTexture,
        const sf::Texture* targetTexture,
        const int stripeCount,
        const float duration,
        const sf::Vector2u& size);

    void update();

    virtual void draw(const DrawParameter& param);

private:
    std::vector<std::unique_ptr<sf::Sprite>> m_sourceSprites;
    std::vector<std::unique_ptr<sf::Sprite>> m_targetSprites;
    int m_stripeWidth;
    int m_stripeHeight;
};

#endif // VERTICALSLIDINGSTRIPES_TRANSITION_HPP