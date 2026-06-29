#include "../include/Game.hpp"

Game::Game() : window(sf::VideoMode({800, 600}), "APM"), player(player)
{
    window.setFramerateLimit(60); // Sets the maximum fps to 60
}

void Game::run()
{
    while (window.isOpen()) // Initializes the game loop.
    {
        float dt = clock.restart().asSeconds(); // Initialize the delta time.

        processEvent();
        update(dt);
        render();
    }
}

void Game::processEvent()
{
    while (const std::optional event = window.pollEvent()) // Initializes the sequence of events, inputs, etc...
    {
        if (event->is<sf::Event::Closed>()) // If the window is closed, the loop terminates.
        {
            window.close();
        }
    }
}

void Game::update(float dt)
{
    player.update(dt);
}

void Game::render()
{
    window.clear(sf::Color::Black); // Sets the window color to black.
    player.render(window);
    window.display(); // Show everything on screen
}
