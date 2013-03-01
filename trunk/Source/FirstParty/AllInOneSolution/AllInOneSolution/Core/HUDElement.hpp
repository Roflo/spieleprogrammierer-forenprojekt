#ifndef HUDELEMENT_HPP
#define HUDELEMENT_HPP

#include "gui\LineLabel.hpp"

class ResourceManager;

/// Basis class for HUD
class HUDElement
{
public:

	static const float Left;
	static const float Right;
	static const float Center;
	static const float Top;
	static const float Middle;
	static const float Bottom;

protected:

    LineLabel m_label;

    sf::Vector2f m_position;

    float m_horizontalPercentage;

    float m_verticalPercentage;

public:
    HUDElement(
        const sf::Vector2f& position,
        const float rotation,
        BitmapFont* bitmapFont,
		const float horizontalPercentage = HUDElement::Left,
        const float verticalPercentage = HUDElement::Top,
        const std::string& text = "");

    virtual ~HUDElement()
    { }

    virtual void update(const DrawParameter& params);

    virtual void draw(const DrawParameter& params);

    void setText(const std::string& text);
};

#endif
