#pragma once

#ifndef MENU_TEMPLATE_HPP
#define MENU_TEMPLATE_HPP

#include "ButtonStyle.hpp"
#include "CheckBoxStyle.hpp"
#include "SliderStyle.hpp"
#include "LineLabel.hpp"
#include "MenuSprite.hpp"
#include "ToolTip.hpp"
#include "../model/SoundObject.hpp"

#include <tinyxml2.h>

#include <string>
#include <vector>

struct ButtonInfo
{
public:
    ButtonInfo(const SoundObject& sound) : sound(sound)
    { }
    ButtonStyle style;
    SoundObject sound;
    sf::Vector2f position;
    std::string textResourceKey;
    int id;
    ToolTip toolTip;
};

struct CheckBoxInfo
{
    CheckBoxStyle style;
    sf::Vector2f position;;
    int id;
};

struct SliderInfo
{
    SliderStyle style;
    sf::Vector2f position;
    int id;
};

struct MenuTemplate
{
    std::vector<ButtonInfo> buttons;
    std::vector<CheckBoxInfo> checkboxes;
    std::vector<SliderInfo> slider;
    std::vector<LineLabel> labels;
    std::vector<MenuSprite> sprites;
    std::string captionResourceKey;
    BitmapFont* captionFont;
    sf::Vector2f captionOffset;
    sf::Sprite background;
};

#endif //MENU_TEMPLATE_HPP
