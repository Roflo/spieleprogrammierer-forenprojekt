#pragma once

#ifndef MENU_PANEL_HPP
#define MENU_PANEL_HPP

#include "MenuTemplate.hpp"
#include "../rendering/Drawable.hpp"

#include <functional>
#include <string>
#include <vector>

class Button;
class CheckBox;
class LineLabel;
class MenuSprite;
class Slider;

class MenuPanel : public Drawable
{
public:

    MenuPanel(const MenuElements& elements, const sf::Vector2f& position);

    virtual void setPosition(const sf::Vector2f& position);
    const sf::Vector2f& getPosition() const;

    virtual void draw(const DrawParameter& params) override;
    virtual void update(const sf::RenderWindow& screen);

    void registerOnClick(std::function<void(const Button& sender)> callback);

    template<class T>
    T& find(int id, const MenuElementType::Type type, const std::string& errorKey) const
    {
        for(auto it = begin(m_elements); it != end(m_elements); ++it)
        {
            if(it->get()->getType() == type && it->get()->getId() == id)
                return *dynamic_cast<T*>(it->get());
        }
        throw std::runtime_error(utility::replace(utility::translateKey(errorKey), utility::toString(id)));
    }

    void add(std::unique_ptr<MenuElement> element);

private:
    
    void createButton(const ButtonInfo& info);
    void createCheckBox(const CheckBoxInfo& info);
    void createSlider(const SliderInfo& info);
    void createLabel(const LineLabel& info);
    void createSprite(const MenuSprite& info);

    sf::Vector2f m_position;
    std::vector<std::unique_ptr<MenuElement>> m_elements;
    std::function<void(const Button& sender)> m_clickCallback;

    void setCorrelation();
};

#endif // MENU_PANEL_HPP
