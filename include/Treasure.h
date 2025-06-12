#pragma once
#include "GameObject.h"

class Treasure : public GameObject {
public:
    Treasure();

    bool isSolid() const override;
};
