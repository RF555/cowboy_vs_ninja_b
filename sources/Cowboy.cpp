#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy() :
            Character(110),
            n_bullets(6) {}

    Cowboy::Cowboy(const string &name, Point point) :
            Character(name, point, 110),
            n_bullets(6) {}

    Cowboy::Cowboy(const Cowboy &_other) :
            Character(_other),
            n_bullets(6) {}

    Cowboy::Cowboy(Cowboy &&_other) noexcept {}

    Cowboy::~Cowboy() = default;

    ostream &Cowboy::toPrint(ostream &output) {
        if (isAlive()) {
            return output << "C " << this->getName() << ", " << this->getLives() << ", " << this->getLocation();
        } else {
            return output << "C " << "(" << this->getName() << "), " << ", " << this->getLocation();
        }
    }

    void Cowboy::shoot(Character *enemy) {}

    bool Cowboy::hasboolets() { return false; }

    void Cowboy::reload() { if (this->n_bullets == 0) this->n_bullets = 6; }

    int Cowboy::getNBullets() const { return n_bullets; }

    Cowboy &Cowboy::operator=(const Cowboy &_other) { return *this; }

    Cowboy &Cowboy::operator=(Cowboy &&_other) noexcept {
        this->setName(_other.getName());
        this->setLives(_other.getLives());
        this->setLocation(_other.getLocation());
        this->n_bullets = _other.getNBullets();
        return *this;
    }
}