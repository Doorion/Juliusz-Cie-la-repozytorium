#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <thread>
#include "../include/Player.h"

int main() {
    std::shared_ptr<Player> player = std::make_shared<Player>();

    std::cout << "Sterowanie: w (góra), s (dół), a (lewo), d (prawo), q (wyjście)\n";

    char input;
    bool running = true;

    while (running) {
        std::cout << "Podaj kierunek: ";
        std::cin >> input;

        switch (input) {
            case 'w': player->move(0, -1); break;
            case 's': player->move(0, 1); break;
            case 'a': player->move(-1, 0); break;
            case 'd': player->move(1, 0); break;
            case 'q': running = false; break;
            default:
                std::cout << "Nieznany ruch!\n";
        }

        player->update(0); // deltaTime = 0 (bo tu nie robimy animacji)
        std::cout << "Pozycja: (" << player->getX() << ", " << player->getY() << ")\n";
    }

    std::cout << "Koniec gry.\n";
    return 0;
}
