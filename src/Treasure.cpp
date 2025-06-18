#include "Treasure.h"

// Dodajemy implementację konstruktora z parametrami
Treasure::Treasure(int x, int y)
    : symbol("T"), solid(false), posX(x), posY(y) {
    // Inicjalizacja sprite'a na pozycji x,y
    sprite.setPosition(x * 32.f, y * 32.f);  // Zakładamy kafelki 32x32 piksele
}

// Reszta metod pozostaje bez zmian
std::string Treasure::getSymbol() const { return symbol; }
bool Treasure::isSolid() const { return solid; }

void Treasure::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Treasure::update(float dt) {
    (void)dt; // Pomijamy ostrzeżenie
}
