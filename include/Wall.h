#pragma once
#include "GameObject.h"

class Wall : public GameObject {
public:
    Wall();

    bool isSolid() const override;
};
