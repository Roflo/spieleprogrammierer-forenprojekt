#include "Slider.hpp"
#include "../Input.hpp"
#include "../Utility.hpp"

Slider::Slider(const int id, const SliderStyle style, const sf::Vector2f& position, const sf::Vector2f& offset) :
    m_id(id),
    m_position(position),
    m_offset(offset),
    m_style(style),
    m_active(false),
    m_pick(0)
{
    m_spriteSlider = &m_style.idle.spriteSlider;
    m_spriteBackround = &m_style.idle.spriteBackround;

    m_sliderPosition.y = m_position.y + m_offset.y + m_style.mouseRect.top;

    m_min = m_style.min;
    m_max = m_style.max;
}

void Slider::update(const sf::RenderWindow& screen)
{
    int x = static_cast<int>(m_position.x + m_offset.x + m_style.mouseRect.left);
    sf::IntRect sliderRect(x, static_cast<int>(m_position.y + m_offset.y + m_style.mouseRect.top),
                           m_style.mouseRect.width,
                           m_style.mouseRect.height);
    
    sf::Vector2f offset(0, 0);
    if(!utility::Mouse.leftButtonPressed())
    {
        m_active = false;
        m_pick = 0;
    }
    else if(!m_active)
    {
        sliderRect.left += static_cast<int>(m_sliderPosition.x);
        sf::Vector2i mousePos = sf::Mouse::getPosition(screen);
        if(sliderRect.contains(mousePos))
        {
            m_active = true;
            m_pick = mousePos.x - sliderRect.left;
        }
    }

    if(!m_active)
    {
        m_spriteSlider = &m_style.idle.spriteSlider;
        m_spriteBackround = &m_style.idle.spriteBackround;
        offset = m_style.idle.sliderOffset;
    }
    else
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screen);
        calculateValue(x, mousePos.x - m_pick);
        m_spriteSlider = &m_style.active.spriteSlider;
        m_spriteBackround = &m_style.active.spriteBackround;
        offset = m_style.active.sliderOffset;
    }
    m_sliderPosition.x = (m_value - m_min) * m_style.width / m_max;
    offset.x += x;
    m_spriteSlider->setPosition(m_sliderPosition + offset);
}

void Slider::draw(const DrawParameter& params)
{
    params.getTarget().draw(*m_spriteBackround);
    params.getTarget().draw(*m_spriteSlider);
}

int Slider::getId() const
{
    return m_id;
}

float Slider::getValue() const
{
    return m_value;
}

void Slider::setPosition(const sf::Vector2f& position)
{
    m_position = position;

    m_style.active.spriteBackround.setPosition(m_position + m_offset + m_style.active.backgroundOffset);
    m_style.idle.spriteBackround.setPosition(m_position + m_offset + m_style.idle.backgroundOffset);

    m_sliderPosition.y = m_position.y + m_offset.y + m_style.mouseRect.top;
}

void Slider::setValue(const float value)
{
    m_value = value;
}

void Slider::calculateSliderPosition(const sf::IntRect& rect)
{
    float posx = rect.width * (m_value / m_max);
    m_sliderPosition.x = rect.left + posx;
}

void Slider::calculateValue(const int left, const int mousex)
{
    float value = m_min + static_cast<float>(mousex - left) / m_style.width * (m_max - m_min);
    m_value = std::max(std::min(value, m_max), m_min);
}
