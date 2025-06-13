#include "Level.h"
#include "Wall.h"
#include "Rock.h"
#include "Treasure.h"
#include "Player.h"
#include "Key.h"
#include "Door.h"
#include "Trap.h"

Level::Level(const std::vector<std::string>& layout) {
    for (int y = 0; y < layout.size(); ++y) {
        for (int x = 0; x < layout[y].size(); ++x) {
            char tile = layout[y][x];
            switch (tile) {
                case '#':
                    objects.push_back(std::make_shared<Wall>(x, y));
                    break;
                case 'R':
                    objects.push_back(std::make_shared<Rock>(x, y));
                    break;
                case 'T':
                    objects.push_back(std::make_shared<Treasure>(x, y));
                    break;
                case 'P':
                    player = std::make_shared<Player>(x, y);
                    objects.push_back(player);
                    break;
                case 'K':
                    objects.push_back(std::make_shared<Key>(x, y));
                    break;
                case 'D':
                    objects.push_back(std::make_shared<Door>(x, y));
                    break;
                case 'a':
                    objects.push_back(std::make_shared<Trap>(x, y, true));  // aktywna
                    break;
                case 'x':
                    objects.push_back(std::make_shared<Trap>(x, y, false)); // nieaktywna
                    break;
                default:
                    break;
            }
        }
    }
}

void Level::draw(sf::RenderWindow& window) {
    for (auto& obj : objects) {
        obj->draw(window);
    }
}

const std::vector<std::shared_ptr<GameObject>>& Level::getObjects() const {
    return objects;
}
void Level::movePlayer(int dx, int dy) {
    if (player) {
        player->move(dx, dy);
    }
}

void Level::update(float dt) {
    for (auto& obj : objects) {
        obj->update(dt);
    }

    if (player) {
        player->update(dt);
    }
}
