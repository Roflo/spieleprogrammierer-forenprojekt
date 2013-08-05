#pragma once

#ifndef MENU_HPP
#define MENU_HPP

#include "../rendering/Drawable.hpp"
#include "MenuTemplate.hpp"
#include "SubWindow.hpp"
#include <SFML/System/Vector2.hpp>

#include <functional>
#include <vector>

class ResourceManager;

class Button;
class CheckBox;
class LineLabel;
class MenuSprite;
class Slider;

namespace sf
{
    class RenderWindow;
};

/// Base-class for menus
class Menu : public Drawable
{
protected:

    void createButton(const ButtonInfo& info);
    void createCheckBox(const CheckBoxInfo& info);
    void createSlider(const SliderInfo& info);
    void createLabel(const LineLabel& info);
    void createSprite(const MenuSprite& info);
    void createSubWindow(const SubWindowInfo& info);

    CheckBox& getCheckboxes(int id);
    Slider& getSlider(int id);
    LineLabel& getLabel(int id);
    Button& getButton(int id);
    sf::RenderWindow& getRenderWindow();
    MenuSprite& getSprite(int id);

    MenuTemplate& getTemplate();

private:

    MenuTemplate m_template;
    std::vector<std::unique_ptr<Button>> m_buttons;
    std::vector<std::unique_ptr<LineLabel>> m_labels;
    std::vector<std::unique_ptr<MenuSprite>> m_sprites;
    std::vector<std::unique_ptr<CheckBox>> m_checkBoxes;
    std::vector<std::unique_ptr<Slider>> m_slider;
    std::vector<std::unique_ptr<SubWindow>> m_subWindow;
    sf::Vector2i m_size;
    sf::Vector2f m_position;
    sf::RenderWindow& m_screen;
    std::function<void(const Button& sender)> m_clickCallback;

    void setCorrelation();
public:

    Menu(const MenuTemplate& menuTemplate,
         const sf::Vector2f& position,
         sf::RenderWindow& screen);

    virtual ~Menu();

    virtual void draw(const DrawParameter& params);

    virtual void update(const sf::RenderWindow& screen);

    virtual void setPosition(const sf::Vector2f& position);

    const sf::Vector2f& getPosition() const;

    const sf::Vector2i& getSize() const;

    void registerOnClick(std::function<void(const Button& sender)> callback);

    void changeIdleSprite(const int id, const sf::Sprite& sprite);
    void changeHoverSprite(const int id, const sf::Sprite& sprite);
    void changePressedSprite(const int id, const sf::Sprite& sprite);

protected:

    virtual void drawAdditionalBackground(const DrawParameter& params);
};

#endif // MENU_HPP