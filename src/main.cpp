#include <SFML/Graphics.hpp>
#include "Level.h"
#include <vector>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "PuzzleGame");

    std::vector<std::string> levelData = {
        "##########",
        "#P..R..K.#",
        "#..##.##.#",
        "#..a....D#",
        "#..##.##.#",
        "#...T.T.T#",
        "##########"
    };

    Level level(levelData);
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::W: level.movePlayer(0, -1); break;
                    case sf::Keyboard::S: level.movePlayer(0, 1); break;
                    case sf::Keyboard::A: level.movePlayer(-1, 0); break;
                    case sf::Keyboard::D: level.movePlayer(1, 0); break;
                    case sf::Keyboard::Q: window.close(); break;
                    default: break;
                }
            }
        }

        float dt = clock.restart().asSeconds();
        level.update(dt);

        window.clear();
        level.draw(window);
        window.display();
    }

    return 0;
}
