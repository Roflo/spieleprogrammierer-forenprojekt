#pragma once

#ifndef MENUSPRITE_HPP
#define MENUSPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "ToolTip.hpp"
#include "../rendering/DrawParameter.hpp"

class MenuSprite : public sf::Sprite
{
public:
    sf::Vector2f m_offset;
    sf::Vector2f m_position;
    
    MenuSprite();
    MenuSprite(const sf::Vector2f& position, const sf::Vector2f& offset, const int id);

    void setOffset(sf::Vector2f offset);
    void setPosition(sf::Vector2f offset);
    void setId(const int id);
    void setToolTip(ToolTip& toolTip);
    sf::Vector2f getOffset();
    sf::Vector2f getPosition();
    int getId();

    void setVisible(const bool visible);
    void draw(const DrawParameter& params);
    void update(const sf::RenderWindow& screen);

private:

    bool m_visible;
    int m_id;
    ToolTip m_toolTip;
    bool m_showToolTip;
};

#endif // MENUSPRITE_HPP