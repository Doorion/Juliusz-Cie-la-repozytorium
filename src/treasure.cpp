#include "Treasure.h"

Treasure::Treasure() {
    frames = { "T", "t" };
    frameTime = 0.4f;
}

bool Treasure::isSolid() const {
    return false;
}
