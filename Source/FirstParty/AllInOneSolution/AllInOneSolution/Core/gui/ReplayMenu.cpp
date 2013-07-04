#include "ReplayMenu.hpp"

ReplayMenu::ReplayMenu(const sf::Vector2f& position,
                       sf::RenderWindow& screen,
                       ResourceManager& resourceManager) :
    CaptionMenu(*resourceManager.getMenuTemplate("replayMenu"), position, screen)
{
}

void ReplayMenu::setPoints(int points)
{
    Menu::getLabel(LABEL_POINTS).setText(utility::toString(points));
}
void ReplayMenu::setSymbol(ResourceManager& resourceManager, sf::IntRect textureRect, std::string textureKey)
{
    if(textureKey != "")
        Menu::getSprite(SPRITE_SYMBOL).setTexture(*resourceManager.getTexture(textureKey));

    Menu::getSprite(SPRITE_SYMBOL).setTextureRect(textureRect);
}