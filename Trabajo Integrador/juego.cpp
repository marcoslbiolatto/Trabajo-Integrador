#include <SFML/Graphics.hpp>
#include "juego.h"
#include "comboy.h"
#include "inocent.h"
#include <iostream>

Juego::Juego() : window(sf::VideoMode(800, 600), "Vaqueros Salvajes") {
    if (!backgroundTexture.loadFromFile("C:/Users/Administrator/source/repos/Trabajo Integrador/asset3/ruta/fondo.png")) {
        std::cerr << "Error al cargar el fondo\n";
    }
    backgroundSprite.setTexture(backgroundTexture);
    updateBackgroundScale();

    if (!crosshairTexture.loadFromFile("C:/Users/Administrator/source/repos/Trabajo Integrador/asset2/ruta/crosshair.png")) {
        std::cerr << "Error al cargar la textura del crosshair\n";
    }
    crosshair.setTexture(crosshairTexture);
    updateCrosshairScale();
}

void Juego::updateBackgroundScale() {
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );
}

void Juego::updateCrosshairScale() {
    float desiredSize = 100.0f;
    sf::Vector2u textureSize = crosshairTexture.getSize();
    crosshair.setScale(
        desiredSize / textureSize.x,
        desiredSize / textureSize.y
    );
}

void Juego::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::Resized) {
            window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            updateBackgroundScale();
            updateCrosshairScale();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            handleShooting();
        }
    }
}

void Juego::handleShooting() {
    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    for (auto it = Comboys.begin(); it != Comboys.end(); ++it) {
        if (it->getSprite().getGlobalBounds().contains(mousePosition)) {
            Comboys.erase(it);
            score++;
            if (score >= 10) gameWon = true;
            break;
        }
    }

    for (auto it = inocent.begin(); it != inocent.end(); ++it) {
        if (it->getSprite().getGlobalBounds().contains(mousePosition)) {
            inocent.erase(it);
            break;
        }
    }
}

void Juego::update() {
    if (gameWon) return;

    if (Comboys.size() < 5) {
        Comboys.emplace_back();
        Comboys.back().spawn(static_cast<float>(rand() % 800), static_cast<float>(rand() % 600));
    }
    if (inocent.size() < 3) {
        inocent.emplace_back();
        inocent.back().spawn(static_cast<float>(rand() % 800), static_cast<float>(rand() % 600));
    }

    // Centrar el crosshair en la posición del cursor
    crosshair.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)) -
        sf::Vector2f(crosshair.getGlobalBounds().width / 2, crosshair.getGlobalBounds().height / 2));
}

void Juego::render() {
    window.clear();

    if (gameWon) {
        // Lógica para mostrar la pantalla "You Win"
    }
    else {
        window.draw(backgroundSprite);
        window.draw(crosshair);

        for (const auto& Comboy : Comboys) {
            Comboy.draw(window);
        }

        for (const auto& inocent : inocent) {
            inocent.draw(window);
        }
    }

    window.display();
}

void Juego::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}
