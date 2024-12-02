#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "juego.h"

class Menu {
public:
    Menu(); // Constructor
    void draw(sf::RenderWindow& window, bool gameStarted); // M�todo para dibujar el men�
    void handleInput(sf::RenderWindow& window, bool& gameStarted); // Manejar la entrada del men�

private:
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
};

#endif