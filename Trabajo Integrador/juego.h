#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "comboy.h"
#include "inocent.h"

class Juego {
public:
    Juego();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleShooting();
    void updateBackgroundScale();  // Declaración de la función
    void updateCrosshairScale();   // Declaración de la función

    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture crosshairTexture;
    sf::Sprite crosshair;
    std::vector<Comboy> Comboys;
    std::vector<Inocent> inocent;
    int score = 0;
    bool gameWon = false;
};

#endif // JUEGO_H
