#include "inocent.h"
#include <iostream>

Inocent::Inocent() {
    if (!texture.loadFromFile("C:/Users/Administrator/source/repos/Trabajo Integrador/asset4/ruta/inocent.png")) {
        std::cerr << "Error al cargar la textura de Inocent\n";
    }
    sprite.setTexture(texture);
    updateScale();
}

void Inocent::updateScale() {
    float desiredSize = 200.0f;
    sf::Vector2u textureSize = texture.getSize();
    sprite.setScale(
        desiredSize / textureSize.x,
        desiredSize / textureSize.y
    );
}

void Inocent::spawn(float x, float y) {
    sprite.setPosition(x, y);
}

void Inocent::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::Sprite Inocent::getSprite() const {
    return sprite;
}
