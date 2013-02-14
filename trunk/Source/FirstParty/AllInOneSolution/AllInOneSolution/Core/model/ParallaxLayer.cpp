#include "ParallaxLayer.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

ParallaxLayer::ParallaxLayer(const sf::Vector2f& layerSize) :
    m_layerSize(layerSize),
    m_updatingAni(nullptr)
{
}


ParallaxLayer::~ParallaxLayer()
{
}

void ParallaxLayer::update(const float time, const sf::View& view, const sf::Vector2u& worldSize)
{
    updateCurrentTime(time);
    
    sf::Vector2f diff = sf::Vector2f(worldSize.x - view.getSize().x, 
                                     worldSize.y - view.getSize().y);
    sf::Vector2f viewPos = view.getCenter() - 0.5f * view.getSize();
    sf::Vector2f percent = sf::Vector2f(viewPos.x / diff.x, viewPos.y / diff.y);

    sf::Vector2f offset = viewPos + sf::Vector2f(
        -(m_layerSize.x - view.getSize().x) * percent.x,
        -(m_layerSize.y - view.getSize().y) * percent.y);

    for(auto animation = getAnimations().begin(); animation != getAnimations().end(); ++animation)
    {
        m_updatingAni = (*animation).get();
        (*animation)->setPosition(offset.x, offset.y);
        (*animation)->update();
    }
    m_updatingAni = nullptr;
}

float ParallaxLayer::getValueOf(const std::string& name) const
{
    if(m_updatingAni == nullptr)
        throw std::runtime_error("Can't evaluate a variable at this time.");
    return m_updatingAni->getValueOf(name);
}
