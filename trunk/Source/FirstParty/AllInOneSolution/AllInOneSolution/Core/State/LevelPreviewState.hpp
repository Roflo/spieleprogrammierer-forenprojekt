#pragma once

#ifndef LEVEL_PREVIEW_STATE_HPP
#define LEVEL_PREVIEW_STATE_HPP

#include "State.hpp"
#include "../gui/LevelPreviewMenu.hpp"
#include "../gui/hud/HUD.hpp"

class Level;

/// This is the option menu.
class LevelPreviewState : public State
{
public:

    LevelPreviewState(sf::RenderWindow& screen, ResourceManager& resourceManager, Config& config);
    ~LevelPreviewState();

    virtual StateChangeInformation update(const float time);
    virtual void draw(const DrawParameter& params);
    virtual void onEnter(const EnterStateInformation* enterInformation, const float time);

private:
    LevelPreviewMenu m_menu;
    Level* m_level;
    bool m_levelUpdated;
    HUD m_HUD;

    EnterPlayStateInformation m_playStateInfo;
    EnterTransitionStateInformation m_transitionStateInfo;
};

#endif // LEVEL_PREVIEW_STATE_HPP