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
    void load(const std::vector<std::string>& mapData);
    void draw(sf::RenderWindow& window);
    std::shared_ptr<Player> getPlayer() const;

private:
    std::vector<std::shared_ptr<GameObject>> objects;
    std::shared_ptr<Player> player;
};
