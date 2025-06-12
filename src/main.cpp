#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "PuzzleGame");

    Player player(5, 5); // startowa pozycja w kafelkach

    sf::Clock clock;  // do mierzenia deltaTime

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::W: player.move(0, -1); break;
                    case sf::Keyboard::S: player.move(0, 1);  break;
                    case sf::Keyboard::A: player.move(-1, 0); break;
                    case sf::Keyboard::D: player.move(1, 0);  break;
                    case sf::Keyboard::Q: window.close();      break;
                    default: break;
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();

        player.update(deltaTime);

        window.clear(sf::Color::Black);
        player.draw(window);
        window.display();
    }

    return 0;
}
