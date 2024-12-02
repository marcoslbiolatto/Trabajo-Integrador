#pragma once
#include <SFML/Graphics.hpp>

class YouWin {
public:
    YouWin();
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};
