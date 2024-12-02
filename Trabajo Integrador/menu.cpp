#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu() {
    // Cargar la imagen del menú
    if (!menuTexture.loadFromFile("C:/Users/Administrator/source/repos/Trabajo Integrador/asset5/ruta/menu.png")) {
        std::cerr << "Error al cargar la imagen del menú\n";
        exit(1);
    }
    menuSprite.setTexture(menuTexture);
}

void Menu::draw(sf::RenderWindow& window, bool gameStarted) {
    // Si el juego no ha comenzado, dibujamos el menú
    if (!gameStarted) {
        window.draw(menuSprite);
    }
}

void Menu::handleInput(sf::RenderWindow& window, bool& gameStarted) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
            gameStarted = true; // Inicia el juego al presionar "A"
        }
    }
}