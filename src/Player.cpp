#include "../include/Player.hpp"

Player::Player(sf::Texture P_Texture) : P_Sprite(P_Texture)
{
    P_Sprite.setPosition({300, 300});
    P_Texture.loadFromFile("");
}

void Player::update(float dt)
{
    speed = 300.f;
    movement = {0.f, 0.f};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= 1.f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += 1.f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.y -= 1.f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.x += 1.f;

    P_Sprite.move(movement * dt *speed);
}

void Player::render(sf::RenderWindow &window)
{
    window.draw(P_Sprite);
}
