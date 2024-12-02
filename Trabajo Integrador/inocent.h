#ifndef INOCENT_H
#define INOCENT_H

#include <SFML/Graphics.hpp>

class Inocent {
public:
    Inocent();
    void spawn(float x, float y);
    void draw(sf::RenderWindow& window) const;
    sf::Sprite getSprite() const;

private:
    void updateScale();  // Declaraci�n de la funci�n
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // INOCENT_H
