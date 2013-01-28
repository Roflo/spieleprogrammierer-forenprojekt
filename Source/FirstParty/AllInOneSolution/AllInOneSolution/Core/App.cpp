#include "App.hpp"
#include "Config.hpp"
#include "utility.hpp" // toString
#include "PlayState.hpp"
#include "LoadLevelState.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <SFML/Audio/Listener.hpp>

#include <sstream>
#include <utility> // move

App::App(Config& config) :
    m_config(config),
    m_windowTitle("Rickety Racket"),
    m_fullscreen(false),
    m_focus(true),
    m_showFps(true),
    m_fps(0),
    m_frameCounter(0.f),
    m_soundBuffer(nullptr)
{
    // Cache often used settings
    m_windowTitle = m_config.get<std::string>("WindowName");
    m_fullscreen = m_config.get<bool>("IsFullScreen");
    m_showFps = m_config.get<bool>("ShowFps");

    // Set the Volume for sf::Sound and sf::Music
    sf::Listener::setGlobalVolume(m_config.get<float>("MasterVolume"));

    sf::VideoMode videoMode(m_config.get<unsigned int>("ResolutionX"), m_config.get<unsigned int>("ResolutionY"));

    adjustVideoMode(videoMode);

    if(m_fullscreen)
    {
        m_screen.create(videoMode, m_windowTitle, sf::Style::Fullscreen);
        // Disable the cursor
        m_screen.setMouseCursorVisible(false);
    }
    else
        m_screen.create(videoMode, m_windowTitle);

    m_fpsText.setFont(*m_resourceManager.getFont("visitor"));
    m_fpsText.setColor(sf::Color::Blue);
    m_fpsText.setCharacterSize(30);
    m_fpsText.setPosition(10, 10);

	m_stateManager.registerState(LoadLevelStateId, std::unique_ptr<LoadLevelState>(new LoadLevelState(m_screen, m_resourceManager, m_config))); 
	m_stateManager.registerState(PlayStateId, std::unique_ptr<PlayState>(new PlayState(m_screen, m_resourceManager, m_config))); 
	m_stateManager.setState(LoadLevelStateId);
}

void App::run()
{
    while(m_screen.isOpen())
    {
        update();
        draw();
    }
}

void App::update()
{
    calculateFps();
    m_fpsText.setString(utility::toString<int>(m_fps));

    handleEvents();
    handleKeyboard();

    m_stateManager.update();
}

void App::draw()
{
    m_screen.clear();

    m_stateManager.draw();

    if(m_showFps)
        m_screen.draw(m_fpsText);
        
    m_screen.display();
}

void App::handleKeyboard()
{
    // Enter to window or fullscreen mode when Press Return+LAlt
    if(m_focus && (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)))
    {
        m_fullscreen = !m_fullscreen;
        
        switchDisplayMode();
    }
}

void App::handleEvents()
{
    sf::Event event;

    while(m_screen.pollEvent(event))
    {
        // Close the window
        if(event.type == sf::Event::Closed)
            m_screen.close();
        else if((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::F))
            m_showFps = !m_showFps;
        else if(event.type == sf::Event::LostFocus)
            m_focus = false;
        else if(event.type == sf::Event::GainedFocus)
            m_focus = true;
        else if(event.type == sf::Event::Resized)
            onResize();
    }
}

void App::switchDisplayMode()
{
    sf::VideoMode videoMode(m_config.get<unsigned int>("ResolutionX"), m_config.get<unsigned int>("ResolutionY"));

    adjustVideoMode(videoMode);

    if(m_fullscreen)
    {
        // Switch to fullscreen
        m_screen.create(sf::VideoMode(videoMode), m_windowTitle, sf::Style::Fullscreen);
        // Disable the cursor
        m_screen.setMouseCursorVisible(false);
    }
    else
    {
        // Switch to window mode
        m_screen.create(sf::VideoMode(videoMode), m_windowTitle);
        // Enable the cursor
        m_screen.setMouseCursorVisible(true);
    }
}

void App::calculateFps()
{
    m_frameCounter++;
    if(m_clock.getElapsedTime().asSeconds() >= 1.0f)
    {
        m_fps = static_cast<int>((m_frameCounter / m_clock.getElapsedTime().asSeconds()));
        m_clock.restart();
        m_frameCounter = 0;
    }
}

void App::onResize()
{
    sf::VideoMode mode(m_screen.getSize().x, m_screen.getSize().y);

    adjustVideoMode(mode);
    
    // Apply possible size changes
    m_screen.setSize(sf::Vector2u(mode.width, mode.height));

    // Reset view
    m_screen.setView(
        sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(mode.width), static_cast<float>(mode.height)))
        );
}

void App::adjustVideoMode(sf::VideoMode& mode)
{
    // Ensure minimas and maximas
    if(mode.width > 1920)
        mode.width = 1920;
    else if(mode.width < 800)
        mode.width = 800;

    if(mode.height > 1080)
        mode.height = 1080;
    else if(mode.height < 600)
        mode.height = 600;

    // Validity of resolution is only important in fullscreen mode
    if(m_fullscreen && !mode.isValid())
    {
        // Get sorted fullscreen modes - best before worse
        const std::vector<sf::VideoMode>& modes = sf::VideoMode::getFullscreenModes();

        for(std::size_t i = 1; i < modes.size(); ++i)
        {
            if(modes[i].width < mode.width && modes[i].height < mode.height &&
                modes[i-1].width <= 1920 && modes[i-1].height <= 1080)
            {
                mode = modes[i-1];
                break;
            }
        }
    }
}