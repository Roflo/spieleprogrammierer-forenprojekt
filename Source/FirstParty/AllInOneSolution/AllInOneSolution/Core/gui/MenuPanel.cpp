#include "MenuPanel.hpp"

#include "Button.hpp"
#include "CheckBox.hpp"
#include "LineLabel.hpp"
#include "MenuSprite.hpp"
#include "Slider.hpp"

MenuPanel::MenuPanel(const MenuElements& elements,
                     const sf::Vector2f& position) :
    m_position(position)
{
    for(auto button = begin(elements.buttons); button != end(elements.buttons); ++button)
        createButton(*button);

    for(auto checkbox = begin(elements.checkboxes); checkbox != end(elements.checkboxes); ++checkbox)
        createCheckBox(*checkbox);

    for(auto slider = begin(elements.slider); slider != end(elements.slider); ++slider)
        createSlider(*slider);

    for(auto label = begin(elements.labels); label != end(elements.labels); ++label)
        createLabel(*label);

    for(auto sprite = begin(elements.sprites); sprite != end(elements.sprites); ++sprite)
        createSprite(*sprite);

    setCorrelation();
    std::sort(m_elements.begin(), m_elements.end(), 
        [](const std::unique_ptr<MenuElement>& a, const std::unique_ptr<MenuElement>& b) -> bool
    { 
        return a->getId() < b->getId(); 
    });
}

void MenuPanel::add(std::unique_ptr<MenuElement> element)
{
    m_elements.push_back(std::move(element));
    std::sort(m_elements.begin(), m_elements.end(), 
        [](const std::unique_ptr<MenuElement>& a, const std::unique_ptr<MenuElement>& b) -> bool
    { 
        return a->getId() < b->getId(); 
    });
}

void MenuPanel::setPosition(const sf::Vector2f& position)
{
    m_position = position;
    for(auto it = begin(m_elements); it != end(m_elements); ++it)
        (*it)->setPosition(m_position);
}

const sf::Vector2f& MenuPanel::getPosition() const
{
    return m_position;
}

void MenuPanel::draw(const DrawParameter& params)
{
    for(auto it = begin(m_elements); it != end(m_elements); ++it)
        (*it)->draw(params);
    
    for(auto it = begin(m_elements); it != end(m_elements); ++it)
        if((*it)->getType() == MenuElementType::Button)
            dynamic_cast<Button*>(it->get())->drawAdditionalForeground(params);
}

void MenuPanel::update(const sf::RenderWindow& screen)
{
    for(auto it = begin(m_elements); it != end(m_elements); ++it)
        (*it)->update(screen);
}

void MenuPanel::setCorrelation()
{
    for(auto s = begin(m_elements); s != end(m_elements); ++s)
    {
        if ((*s)->getType() != MenuElementType::Image)
            continue;
        auto sprite = dynamic_cast<MenuSprite*>(s->get());
        auto id = sprite->getVisibleWhenId();
        if(id == -1 || sprite->getId() == id)
            continue;

        for(auto it = begin(m_elements); it != end(m_elements); ++it)
            if((*it)->getId() == id)
                sprite->setVisibleWhenSubject(it->get());
    }
}

void MenuPanel::createButton(const ButtonInfo& info)
{
    std::unique_ptr<Button> button(new Button(info.id, info.style, m_position, info.position));

    button->registerOnPressed([this](const Button& sender)
    {
        if(m_clickCallback != nullptr)
            m_clickCallback(sender);
    });

    button->setToolTip(info.toolTip);
    m_elements.push_back(std::move(button));
}

void MenuPanel::createCheckBox(const CheckBoxInfo& info)
{
    std::unique_ptr<CheckBox> checkbox(new CheckBox(info.id, info.style, m_position, info.position));
    m_elements.push_back(std::move(checkbox));
}

void MenuPanel::createSlider(const SliderInfo& info)
{
    std::unique_ptr<Slider> slider(new Slider(info.id, info.style, m_position, info.position));
    m_elements.push_back(std::move(slider));
}

void MenuPanel::createLabel(const LineLabel& info)
{
    std::unique_ptr<LineLabel> label(new LineLabel(info));
    m_elements.push_back(std::move(label));
}

void MenuPanel::createSprite(const MenuSprite& info)
{
    std::unique_ptr<MenuSprite> sprite(new MenuSprite(info));
    m_elements.push_back(std::move(sprite));
}

void MenuPanel::registerOnClick(std::function<void(const Button& sender)> callback)
{
    m_clickCallback = callback;
}
