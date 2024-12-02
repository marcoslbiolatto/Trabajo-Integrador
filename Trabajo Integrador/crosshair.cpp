#include "Crosshair.h"
#include <iostream>
#include <SFML/Graphics.hpp> // Aseg�rate de incluir esto si no lo tienes

// Constructor de Crosshair
Crosshair::Crosshair() {
    // Intentamos cargar la textura desde una ruta relativa (por ejemplo)
    if (!texture.loadFromFile("C:/Users/Administrator/source/repos/Trabajo Integrador/asset2/ruta/crosshair.png")) {  // Usa una ruta relativa si es posible
        std::cerr << "Error al cargar la textura de la mira desde la ruta: C:/Users/Administrator/source/repos/Trabajo Integrador/asset2/ruta/crosshair.png";
    }
    else {
        // Si la textura se carga correctamente, configuramos el sprite
        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f); // Aseg�rate de usar 'f' para indicar flotante
    }
}

// M�todo para establecer la posici�n de la mira
void Crosshair::setPosition(const sf::Vector2f& position) {
    sprite.setPosition(position);
}

// M�todo para dibujar la mira en la ventana
void Crosshair::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}