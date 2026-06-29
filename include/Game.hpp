#pragma once
#include <SFML/Graphics.hpp>
#include "../include/Player.hpp"

class Game
{
public:
    Game(); // It is a constructor that initializes the main variables.
    void run(); // Initializes the game loop that repeats every frame.

private:
    void processEvent(); // handles events, input, etc...
    void update(float dt); // It updates everything every frame.
    void render(); // Renders everything to the screen.

    sf::RenderWindow window;
    sf::Clock clock;
    Player player;
};