#include "Entity.hpp"
#include "../Utility.hpp"

#include <exception>

#include <SFML/Graphics/RenderTarget.hpp>

#include <Box2D/Dynamics/b2World.h>

Entity::Entity(Type type, bool respawnable, bool autoKill) :
    m_killed(false),
    m_type(type),
    m_updatingAni(nullptr),
    m_collideWithBall(true),
    m_respawnable(respawnable),
    m_autoKill(autoKill)
{
}

Entity::~Entity()
{
}

void Entity::update(const float value)
{
    if(!m_killed)
    {
        removeStoppedAnimations();

        updateCurrentTime(value);
        updateKinematics(getPassedTime(), value - m_lastTime);
        bool running = false;
        for(auto animation = begin(getAnimations()); animation != end(getAnimations()); ++animation)
        {
            auto ani = (*animation).get();
            if(ani->isStopped())
                continue;
            m_updatingAni = ani;
            ani->setPosition(utility::toPixel(getPosition().x), utility::toPixel(getPosition().y));
            if(getBody() != nullptr)
                ani->setRotation(getBody()->GetAngle());
            ani->update();
            running |= !ani->isStopped();
        }
        m_updatingAni = nullptr;
        m_lastTime = value;

        if(!running && m_autoKill)
            kill();
    }
    
    if(isStopped())
        kill();
}

float Entity::getValueOf(const std::string& name) const
{
    auto match = m_variables.find(name);
    if(match == end(m_variables))
    {
        if(m_updatingAni == nullptr)
            throw std::runtime_error(utility::replace(utility::translateKey("GetVariable"), name));
        return m_updatingAni->getValueOf(name);
    }
    return match->second;
}

void Entity::setValueOf(const std::string& name, const float value)
{
    if(m_updatingAni == nullptr)
        m_variables[name] = value;
    else
    {
        auto match = m_variables.find(name);
        if(match == end(m_variables))
            m_updatingAni->setValueOf(name, value);
        else
            m_variables[name] = value;
    }
}

void Entity::setName(std::string name)
{
    m_name = name;
}

const Entity::Type& Entity::getType() const
{
    return m_type;
}

void Entity::restartAt(const float value)
{
    TimedObject::restartAt(value);
    m_lastTime = value;
    m_killed = false;

    for(auto animation = begin(getAnimations()); animation != end(getAnimations()); ++animation)
        (*animation)->reset();
}

void Entity::kill()
{    
    m_killed = true;
}

bool Entity::killed() const
{
    return m_killed;
}

bool Entity::isRespawnable() const
{
    return m_respawnable;
}

void Entity::setCollideWithBall(bool value)
{
    m_collideWithBall = value;
}

bool Entity::doesCollideWithBall()
{
    return m_collideWithBall;
}

void Entity::bindCollisionSound(std::unique_ptr<SoundObject> sound)
{
    m_collisionSound = std::move(sound);
}

void Entity::bindCollisionHandler(std::unique_ptr<CollisionHandler> handler)
{
    m_collisionHandler.push_back(std::move(handler));
}

void Entity::bindCollisionFilter(std::unique_ptr<CollisionFilter> filter)
{
    m_collisionFilter = std::move(filter);
}

void Entity::onCollide(Entity* partner, const b2Vec2& point, const float impulse)
{
    if(m_collisionSound != nullptr)
    {
        float volume = std::min(100.f, std::max(impulse/4.f, 0.f));
        if(volume > 10 || m_collisionSound->hasFixedVolume())
            m_collisionSound->play(volume);
    }

    for(auto it = begin(m_collisionHandler); it != end(m_collisionHandler); ++it)
        (*it)->onCollision(this, partner, point, impulse);
}

bool Entity::shouldCollide(Entity* partner)
{
    if(m_collisionFilter == nullptr)
        return true;
    return m_collisionFilter->shouldCollide(this, partner);
}