#pragma once

#ifndef MENUSPRITE_HPP
#define MENUSPRITE_HPP

#include "MenuElement.hpp"
#include "ToolTip.hpp"

#include <SFML/Graphics/Sprite.hpp>

class MenuSprite : public MenuElement
{
public:

    MenuSprite(const sf::Sprite& sprite, const sf::Vector2f& position, const sf::Vector2f& offset, const int id);

    void setToolTip(const ToolTip& toolTip);
    void setToolTipText(const std::string& text);
    void setTextureRect(const sf::IntRect& textureRect);
    void setVisibleWhenId(const int id);
    int getVisibleWhenId() const;
    void setVisibleWhenSubject(const MenuElement* subject);

    virtual void draw(const DrawParameter& params) override;
    virtual void update(const sf::RenderWindow& screen) override;

protected:

    virtual void onPositionChanged() override;

private:

    sf::Sprite m_sprite;
    ToolTip m_toolTip;
    bool m_showToolTip;

    struct Correlation
    {
        Correlation() : id(-1), subject(nullptr)
        {}
        int id;
        const MenuElement* subject;
    };

    Correlation m_visibleWhen;
};

#endif // MENUSPRITE_HPP