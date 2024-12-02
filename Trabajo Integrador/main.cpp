#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Juego.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 600), "Juego de Vaqueros");
    Menu menu;
    Juego juego;
    bool gameStarted = false;

    while (window.isOpen()) {
        menu.handleInput(window, gameStarted);

        if (gameStarted) {
            juego.run();
            window.close();
        }

        window.clear();
        menu.draw(window, gameStarted);
        window.display();
    }

    return 0;
}
