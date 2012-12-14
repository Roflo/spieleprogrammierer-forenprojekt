#pragma once

#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Ball.hpp"
#include "../DebugDraw.hpp"
#include "Background.hpp"
#include "../animation/TimedObject.hpp"
#include "../ContactFilter.hpp"
#include "../ScrollView.hpp"

#include <Box2D/Dynamics/b2World.h>
#include <Box2D/Collision/Shapes/b2Shape.h>

#include <memory> // unique_ptr
#include <string>
#include <unordered_map>
#include <vector>

class Config;

class ResourceManager;

namespace sf
{
    class RenderWindow;
}

namespace tinyxml2
{
    class XMLDocument;
    class XMLElement;
}

/// Manages the different levels and is
/// also resposible for loading them.
class Level : public TimedObject
{
public:
    /// Construct a level from the given level number
    Level(const unsigned int level, ResourceManager& resourceManager, Config& config);
    ~Level();

    virtual void restartAt(const float time);
    void update(const float dt);
    void draw(sf::RenderWindow& screen);

    /// Return the level number
    const unsigned int number();

    const float getWidth() const;
    const float getHeight() const;

private:
    /// Load the level after m_number
    bool load();

    /// Validate the XML file
    bool validate(const tinyxml2::XMLDocument& document);

    /// Create an Entity
    std::unique_ptr<Entity> createEntity(tinyxml2::XMLElement* xml, const sf::Vector2u& position,
        tinyxml2::XMLElement* shape, tinyxml2::XMLElement* physic);

    /// Construct the full level filename from the level number
    const std::string filename();

private:

    b2World m_world;

    ResourceManager& m_resourceManager;

    unsigned int m_number;

    std::vector<std::unique_ptr<Entity>> m_entities;

    // HACK: This should be in the Entity class, but since unique_ptr sucks with VS10...
    std::vector<std::unique_ptr<b2Shape>> m_shapes;

    std::unique_ptr<Background> m_background;

    ContactFilter m_contactFilter;

    float m_timeStep;
    int m_velocityIterations;
    int m_positionIterations;

    float m_width;
    float m_height;

    float m_lastTime;

    Config& m_config;

	bool m_debugDraw;

	ScrollView m_scrollView;
	Ball* m_ball;
};

#endif // LEVEL_HPP