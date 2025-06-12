#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:
    Player(int x, int y);

    bool isSolid() const override;
    void move(int dx, int dy);
    int getX() const;
    int getY() const;

private:
    int x, y;
};

