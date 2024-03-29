#ifndef HUDELEMENT_HPP
#define HUDELEMENT_HPP

#include <SFML/System/Vector2.hpp>
#include "../../rendering/Drawable.hpp"

class ResourceManager;

/// Basis class for HUD
class HUDElement : public Drawable
{
public:

    static const float Left;
    static const float Right;
    static const float Center;
    static const float Top;
    static const float Middle;
    static const float Bottom;

private:

    sf::Vector2f m_position;
    sf::Vector2f m_currentPosition;

    float m_horizontalPercentage;

    float m_verticalPercentage;

public:
    HUDElement(
        const sf::Vector2f& position,
        const float rotation,
        const float horizontalPercentage = HUDElement::Left,
        const float verticalPercentage = HUDElement::Top);

    virtual ~HUDElement()
    { }

    virtual void update(const DrawParameter& params);

    virtual void draw(const DrawParameter& params) = 0;

    void setPosition(const sf::Vector2f& position, const float horizontalPercentage = HUDElement::Left, const float verticalPercentage = HUDElement::Top);

protected:
    const sf::Vector2f getPosition() const;
};

#endif
