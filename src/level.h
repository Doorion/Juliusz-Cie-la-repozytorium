
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
#include "GameObject.h"
#include "Player.h"

class Level {
public:
    Level();
    Level(const std::vector<std::string>& mapData);
    void load(const std::vector<std::string>& mapData);
    void draw(sf::RenderWindow& window);
    std::shared_ptr<Player> getPlayer() const;

    void movePlayer(int dx, int dy);
    void update(float dt);
    const std::vector<std::shared_ptr<GameObject>>& getObjects() const;


private:
    std::vector<std::shared_ptr<GameObject>> objects;
    std::shared_ptr<Player> player;
};
