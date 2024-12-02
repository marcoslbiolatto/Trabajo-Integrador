#include "YouWincpp.h"
#include <iostream>
#include <SFML/Graphics.hpp>
YouWin::YouWin() {
    if (!texture.loadFromFile("C:/Users/Administrator/source/repos/Trabajo Integrador/asset6/ruta/youwin.png")) {
        std::cerr << "Error al cargar la pantalla de victoria\n";
    }
    sprite.setTexture(texture);
}

void YouWin::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}