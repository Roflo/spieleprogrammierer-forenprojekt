#include "SubWindow.hpp"

#include "Button.hpp"
#include "CheckBox.hpp"
#include "LineLabel.hpp"
#include "MenuSprite.hpp"
#include "Slider.hpp"

#include "../gui/Menu.hpp"
#include "../Input.hpp"
#include "../rendering/DrawParameter.hpp"
#include "../Utility.hpp"

SubWindow::SubWindow(const int id,
                     const sf::Vector2f& position,
                     const sf::Vector2f& size,
                     const sf::Vector2f& offset,
                     const int innerHeight,
                     const MenuElements& elements,
                     const SubWindowStyle& style) :
    MenuElement(id, MenuElementType::SubWindow, position, offset),
    m_panel(elements, position),
    m_size(size),
    m_innerHeight(innerHeight),
    m_startValue(0),
    m_endValue(0),
    m_active(false),
    m_style(style)
{
    float scrollWidth = static_cast<float>(m_style.scrollbarTop.getTextureRect().width);
    m_windowRect.setPosition(position.x + offset.x,
                             position.y + offset.y);
    m_windowRect.setSize(sf::Vector2f(size.x - scrollWidth, size.y));
    m_windowRect.setFillColor(sf::Color(100, 100, 100, 70));

    m_sliderRect.setPosition(position.x + offset.x + m_size.x - scrollWidth,
                             position.y + offset.y);
    m_sliderRect.setSize(sf::Vector2f(scrollWidth, m_size.y));
    m_sliderRect.setFillColor(sf::Color(40, 40, 40, 70));

    m_positionRect.setPosition(position.x + offset.x + m_size.x - scrollWidth,
                               position.y + offset.y);

    float positionSize = m_size.y / m_innerHeight;
    if(positionSize > 1.f)
        positionSize = 1.f;

    m_positionRect.setSize(sf::Vector2f(m_sliderRect.getSize().x, floorf(m_size.y * positionSize)));
    m_positionRect.setFillColor(sf::Color(128, 128, 128, 250));

    m_center.x = m_size.x / 2.f;
    m_center.y = m_size.y / 2.f;
}

MenuPanel* SubWindow::getPanel()
{
    return &m_panel;
}

void SubWindow::on(const DrawParameter& params)
{
    m_orginalView = params.getTarget().getView();
    auto position = getPosition();
    auto offset = getOffset();
    auto orginalScreenRect = params.getTarget().getSize();
    sf::FloatRect windowViewport;
    windowViewport.left = (position.x + offset.x) / (orginalScreenRect.x - 0.2f);
    windowViewport.top = (position.y + offset.y) / (orginalScreenRect.y - 0.2f);
    windowViewport.width = m_size.x / (orginalScreenRect.x - 0.2f);
    windowViewport.height = m_size.y / (orginalScreenRect.y - 0.2f);
    sf::View windowView;
    windowView.setViewport(windowViewport);
    windowView.setCenter(m_center);
    windowView.setSize(m_size);
    params.getTarget().setView(windowView);
}

void SubWindow::off(const DrawParameter& params)
{
    params.getTarget().setView(m_orginalView);
}

void SubWindow::draw(const DrawParameter& params)
{
    if(!isVisible())
        return;

    params.getTarget().draw(m_windowRect);
    params.getTarget().draw(m_sliderRect);

    params.getTarget().draw(m_style.scrollbarTop);
    params.getTarget().draw(m_style.scrollbarMiddle);
    params.getTarget().draw(m_style.scrollbarBottom);

    on(params);
    m_panel.draw(params);
    off(params);
}

void SubWindow::update(const sf::RenderWindow& screen)
{
    sf::IntRect mouseRect(static_cast<sf::Vector2i>(m_windowRect.getPosition()), static_cast<sf::Vector2i>(m_windowRect.getSize()));
    sf::IntRect sliderRect(static_cast<sf::Vector2i>(m_positionRect.getPosition()), static_cast<sf::Vector2i>(m_positionRect.getSize()));

    if(mouseRect.contains(sf::Mouse::getPosition(screen)) && utility::Mouse.isWheelMovedDown())
    {
        if((m_center.y + 15) < (m_innerHeight - m_size.y / 2.f))
            m_center.y += 15;
        else
            m_center.y = m_innerHeight - m_size.y / 2.f;
    }
    else if(mouseRect.contains(sf::Mouse::getPosition(screen)) && utility::Mouse.isWheelMovedUp())
    {
        if((m_center.y - 15) > (m_size.y / 2.f))
            m_center.y -= 15;
        else
            m_center.y = m_size.y / 2.f;
    }

    if(sliderRect.contains(sf::Mouse::getPosition(screen)) && utility::Mouse.leftButtonDown())
    {
        m_startValue = sf::Mouse::getPosition().y;
        m_active = true;
    }
    else if(utility::Mouse.leftButtonPressed() && m_active)
    {
        m_endValue = sf::Mouse::getPosition().y;
        float y = m_positionRect.getPosition().y + m_endValue - m_startValue;
        if(y < getPosition().y + getOffset().y)
            y = getPosition().y + getOffset().y;
        if(y > getPosition().y + getOffset().y + m_size.y - m_positionRect.getSize().y)
            y = getPosition().y + getOffset().y + m_size.y - m_positionRect.getSize().y;
        m_positionRect.setPosition(m_positionRect.getPosition().x, y);

        m_center.y = floorf(m_size.y / 2.f + sliderPixelToWindowPixel(m_positionRect.getPosition().y - getPosition().y - getOffset().y));
        m_startValue = m_endValue;
    }
    else if(utility::Mouse.leftButtonReleased())
        m_active = false;

    auto pos = m_positionRect.getPosition();
    m_style.scrollbarTop.setPosition(pos);
    m_style.scrollbarMiddle.setPosition(pos.x, pos.y + m_style.scrollbarTop.getTextureRect().height);
    float height = m_positionRect.getSize().y
                    - m_style.scrollbarTop.getTextureRect().height
                    - m_style.scrollbarBottom.getTextureRect().height;
    m_style.scrollbarMiddle.setScale(1, height/m_style.scrollbarMiddle.getTextureRect().height);
    m_style.scrollbarBottom.setPosition(pos.x, pos.y + height + m_style.scrollbarTop.getTextureRect().height);
}

void SubWindow::onPositionChanged()
{
    float scrollWidth = static_cast<float>(m_style.scrollbarTop.getTextureRect().width);
    auto position = getPosition();
    auto offset = getOffset();
    m_windowRect.setPosition(position.x + offset.x,
                             position.y + offset.y);
    m_sliderRect.setPosition(position.x + offset.x + m_size.x - scrollWidth,
                             position.y + offset.y);
    m_positionRect.setPosition(position.x + offset.x + m_size.x - scrollWidth,
                               position.y + offset.y);
}

float SubWindow::sliderPixelToWindowPixel(float pixel)
{
    return pixel * (m_innerHeight - m_size.y) / (m_sliderRect.getSize().y - m_positionRect.getSize().y);
}