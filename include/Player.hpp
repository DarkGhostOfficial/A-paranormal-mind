#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(sf::Texture P_Texture);
    void update(float dt);
    void render(sf::RenderWindow& window);

private:
    sf::Sprite P_Sprite;

    sf::Vector2f movement;
    float speed;
};