#ifndef COMBOY_H
#define COMBOY_H

#include <SFML/Graphics.hpp>

class Comboy {
public:
    Comboy();
    void spawn(float x, float y);
    void draw(sf::RenderWindow& window) const;
    sf::Sprite getSprite() const;

private:
    void updateScale();  // Declaraci�n de la funci�n
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // COMBOY_H
