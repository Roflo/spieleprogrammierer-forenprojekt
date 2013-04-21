#include "RandomTransition.hpp"
#include "GrowingRectangleTransition.hpp"
#include "GrowingCircleTransition.hpp"
#include "HorizontalMaskingStripesTransition.hpp"
#include "VerticalMaskingStripesTransition.hpp"
#include "VerticalStripesTransition.hpp"
#include "HorizontalStripesTransition.hpp"
#include "AlphaTransition.hpp"
#include "VerticalSlidingStripesTransition.hpp"
#include "HorizontalSlidingStripesTransition.hpp"
#include "HorizontalHalvesTransition.hpp"
#include "VerticalHalvesTransition.hpp"
#include "HorizontalSlicesTransition.hpp"
#include "VerticalSlicesTransition.hpp"
#include "RotatingSquaresTransition.hpp"
#include "HorizontalCompressTransition.hpp"
#include "VerticalCompressTransition.hpp"
#include "HorizontalExpandTransition.hpp"
#include "VerticalExpandTransition.hpp"
#include "HorizontalSpringTransition.hpp"
#include "VerticalSpringTransition.hpp"

#include "../../animation/Provider/RandomProvider.hpp"

int RandomTransition::m_lastTransition = static_cast<RandomTransition::TransitionType>(TypeCount);

RandomTransition::RandomTransition(const sf::Texture* sourceTexture,
                                   const sf::Texture* targetTexture,
                                   const float duration) :
m_maxHorizontalLines(21),
m_maxVerticalLines(21),
m_transition(nullptr)
{
    bool sourceExist = false;
    bool targetExist = false;

    if(sourceTexture != nullptr)
        sourceExist = true;
    if(targetTexture != nullptr)
        targetExist = true;

    auto transition = createTransition(sourceTexture,
                                       targetTexture,
                                       duration,
                                       randomNumber(sourceExist, targetExist));

    m_transition.reset(transition);
}

int RandomTransition::randomNumber(bool sourceExist, bool targetExist)
{
    float min = 0;
    float max = static_cast<float>(TypeCount);
    
    if(sourceExist == false && targetExist == false)
        return static_cast<int>(Alpha);        
    else if(sourceExist && targetExist == false)
    {
        min = static_cast<float>(HorizontalHalves);
        max = static_cast<float>(Alpha);
    }
    else if(targetExist && sourceExist == false)
    {
        min = static_cast<float>(Alpha);
        max = static_cast<float>(VerticalStripes);
    }
    
    int random = static_cast<int>(RandomProvider(min, max).getValue());
    
    while(random == m_lastTransition)
        random = static_cast<int>(RandomProvider(min, max).getValue());

    m_lastTransition = random;

    return random;
}

Transition* RandomTransition::createTransition(const sf::Texture* sourceTexture,
                                               const sf::Texture* targetTexture,
                                               const float duration,
                                               int randomCount)
{

    TransitionType type = static_cast<TransitionType>(randomCount);

    int vertical = static_cast<int>(RandomProvider(2, static_cast<float>(m_maxVerticalLines)).getValue());
    int horizontal = static_cast<int>(RandomProvider(2, static_cast<float>(m_maxHorizontalLines)).getValue());

    switch(type)
    {
        case HorizontalHalves:
            return (new HorizontalHalvesTransition(sourceTexture, targetTexture, horizontal, duration));
        case VerticalHalves:
            return (new VerticalHalvesTransition(sourceTexture, targetTexture, vertical, duration));
        case Alpha:
            return (new AlphaTransition(sourceTexture, targetTexture, duration));
        case GrowingCircle:
            return (new GrowingCircleTransition(sourceTexture, targetTexture, duration));
        case GrowingRectangle:
            return (new GrowingRectangleTransition(sourceTexture, targetTexture, duration));
        case HorizontalMaskingStripes:
            return (new HorizontalMaskingStripesTransition(sourceTexture, targetTexture, horizontal, duration));
        case HorizontalSlices:
            return (new HorizontalSlicesTransition(sourceTexture, targetTexture, horizontal, duration));
        case HorizontalStripes:
            return (new HorizontalStripesTransition(sourceTexture, targetTexture, horizontal, duration));
        case RotatingSquares:
            return (new RotatingSquaresTransition(sourceTexture, targetTexture, horizontal, vertical, duration));
        case VerticalMaskingStripes:
            return (new VerticalMaskingStripesTransition(sourceTexture, targetTexture, vertical, duration));
        case VerticalSlices:
            return (new VerticalSlicesTransition(sourceTexture, targetTexture, vertical, duration));
        case VerticalStripes:
            return (new VerticalStripesTransition(sourceTexture, targetTexture, vertical, duration));
        case VerticalSlidingStripes:
            return (new VerticalSlidingStripesTransition(sourceTexture, targetTexture, vertical, duration));
        case HorizontalSlidingStripes:
            return (new HorizontalSlidingStripesTransition(sourceTexture, targetTexture, horizontal, duration));
        case HorizontalCompress:
            return (new HorizontalCompressTransition(sourceTexture, targetTexture, horizontal, duration));
        case VerticalCompress:
            return (new VerticalCompressTransition(sourceTexture, targetTexture, vertical, duration));
        case HorizontalExpand:
            return (new HorizontalExpandTransition(sourceTexture, targetTexture, horizontal, duration));
        case VerticalExpand:
            return (new VerticalExpandTransition(sourceTexture, targetTexture, vertical, duration));
        case HorizontalSpring:
            return (new HorizontalSpringTransition(sourceTexture, targetTexture, horizontal - 1, duration));
        case VerticalSpring:
            return (new VerticalSpringTransition(sourceTexture, targetTexture, vertical - 1, duration));
        case TypeCount:
        default:
        break;
    }
    throw std::runtime_error(utility::replace(utility::translateKey("RandomTransition"), utility::toString(randomCount)));
}

bool RandomTransition::isFinished()
{
    return m_transition->isFinished();
}

void RandomTransition::update()
{
    m_transition->update();
}

void RandomTransition::draw(const DrawParameter& param)
{
    m_transition->draw(param);
}