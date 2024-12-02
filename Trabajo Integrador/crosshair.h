#pragma once
#include <SFML/Graphics.hpp>

class Crosshair {
public:
    Crosshair();
    void setPosition(const sf::Vector2f& position);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};