#include <SFML/Graphics.hpp>
#include "Level.h"
#include <vector>
#include <string>
#include <stdexcept> // dla std::runtime_error

int main() {
    try {
        // Inicjalizacja okna
        sf::RenderWindow window(sf::VideoMode(640, 480), "PuzzleGame");
        window.setFramerateLimit(60); // Ograniczenie do 60 FPS

        // Definicja poziomu
        const std::vector<std::string> levelData = {
            "##########",
            "#P..R..K.#",
            "#..##.##.#",
            "#..a....D#",
            "#..##.##.#",
            "#...T.T.T#",
            "##########"
        };

        // Inicjalizacja poziomu
        Level level;
        try {
            level.load(levelData);
        } catch (const std::exception& e) {
            throw std::runtime_error("Failed to load level: " + std::string(e.what()));
        }

        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        const sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 FPS

        // Główna pętla gry
        while (window.isOpen()) {
            // Obsługa czasu
            timeSinceLastUpdate += clock.restart();
            while (timeSinceLastUpdate > timePerFrame) {
                timeSinceLastUpdate -= timePerFrame;

                // Obsługa zdarzeń
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }

                    if (event.type == sf::Event::KeyPressed) {
                        switch (event.key.code) {
                        case sf::Keyboard::W: level.movePlayer(0, -1); break;
                        case sf::Keyboard::S: level.movePlayer(0, 1); break;
                        case sf::Keyboard::A: level.movePlayer(-1, 0); break;
                        case sf::Keyboard::D: level.movePlayer(1, 0); break;
                        case sf::Keyboard::Q: window.close(); break;
                        case sf::Keyboard::Escape: window.close(); break;
                        default: break;
                        }
                    }
                }

                // Aktualizacja logiki gry
                level.update(timePerFrame.asSeconds());
            }

            // Renderowanie
            window.clear(sf::Color::Black);
            level.draw(window);
            window.display();
        }
    } catch (const std::exception& e) {
        // Obsługa błędów
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unknown error occurred!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
