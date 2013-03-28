#ifndef LINELABEL_HPP
#define LINELABEL_HPP

#pragma once

#include "../animation/Interpolation.hpp"
#include "../rendering/Drawable.hpp"
#include "BitmapFont.hpp"

#include <SFML/System/Vector2.hpp>

#include <memory>

/// This class will be used to draw a single line label 
/// with bitmapfonts
class LineLabel : public Drawable
{
public:

    enum Alignment
    {
        Left,
        Centered,
        Right
    };

    LineLabel();
    LineLabel(const std::string& text,
        const sf::Vector2f& position,
        const float rotation,
        BitmapFont* font,
        const Alignment alignment = Left);

    void setText(const std::string& text);
    std::string getText() const;
    float getWidth() const;

    void setPosition(const sf::Vector2f position);
    void setPosition(const float x, const float y);
    const sf::Vector2f getPosition() const;
    void setAlignment(const Alignment alignment);

    void attachPositionProgress(const Interpolation& x, const Interpolation& y);
    void attachAlphaProgress(const Interpolation& alpha);
    void updateProgress(const float time);
    bool anyProgressRunning();
    bool allProgressesFinished();

    void setRotation(const float angle);
    float getRotation() const;

    void setBitmapFont(BitmapFont* font);

    void draw(const DrawParameter& params);

private:

    void rebuild();

    float m_width;
    std::string m_text;
    sf::Vector2f m_position;
    float m_rotation;
    BitmapFont* m_font;
    std::vector<BitmapFont::Glyph> m_glyphs;
    Alignment m_alignment;

    sf::Vector2f m_progressPosition;
    Interpolation m_xPosChange;
    Interpolation m_yPosChange;
    Interpolation m_alphaChange;
};

#endif // LINELABEL_HPP