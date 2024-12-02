#include "comboy.h"
#include <iostream>

Comboy::Comboy() {
    if (!texture.loadFromFile("C:/Users/Administrator/source/repos/Trabajo Integrador/asset1/ruta/comboy.png")) {
        std::cerr << "Error al cargar la textura de Comboy\n";
    }
    sprite.setTexture(texture);
    updateScale();
}

void Comboy::updateScale() {
    float desiredSize = 200.0f;
    sf::Vector2u textureSize = texture.getSize();
    sprite.setScale(
        desiredSize / textureSize.x,
        desiredSize / textureSize.y
    );
}

void Comboy::spawn(float x, float y) {
    sprite.setPosition(x, y);
}

void Comboy::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::Sprite Comboy::getSprite() const {
    return sprite;
}
