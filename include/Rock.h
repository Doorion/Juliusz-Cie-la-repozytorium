#pragma once
#include "GameObject.h"

class Rock : public GameObject {
public:
    Rock();

    bool isSolid() const override;
};
