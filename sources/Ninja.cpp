#include "Ninja.hpp"

namespace ariel {

    Ninja::Ninja() :
            Character(),
            _speed(0) {}

    Ninja::Ninja(int lives, int speed) :
            Character(lives),
            _speed(speed) {}

    Ninja::Ninja(const string &name, Point point, int lives, int speed) :
            Character(name, point, lives, NINJA),
            _speed(speed) {}

    Ninja::Ninja(const Ninja &_other) : Character(_other), _speed(_other._speed) {}

    Ninja::Ninja(Ninja &&_other) noexcept {}

    Ninja::~Ninja() = default;

    ostream &Ninja::toPrint(ostream &output) {
        if (isAlive()) {
            return output << "N " << this->getName() << ", " << this->getLives() << ", " << this->getLocation();
        } else {
            return output << "N " << "(" << this->getName() << "), " << ", " << this->getLocation();
        }
    }

    int Ninja::getSpeed() const { return _speed; }

    Ninja &Ninja::operator=(const Ninja &_other) { return *this; }

    Ninja &Ninja::operator=(Ninja &&_other) noexcept {
        this->setName(_other.getName());
        this->setLives(_other.getLives());
        this->setLocation(_other.getLocation());
        this->_speed = _other.getSpeed();
        return *this;
    }

    void Ninja::setSpeed(int speed) { _speed = speed; }

    void Ninja::slash(Character *enemy) {
        if (this->isAlive() && enemy->isAlive()) {
            if (this->distance(enemy) <= 1) {
                enemy->hit(40);
            }
        } else if (this->isAlive()) {
            throw std::runtime_error("RUNTIME ERROR: Dead Ninja can not attack!\n");
        } else {
            throw std::runtime_error("RUNTIME ERROR: Cowboy can not attack a dead Character!\n");
        }
    }

    void Ninja::move(Character *enemy) {
        this->getLocation().movePoint(
                this->getLocation().moveTowards(getLocation(), enemy->getLocation(), this->_speed));
    }

    void Ninja::attack(Character *enemy) {
        if (this->distance(enemy) <= 1) {
            slash(enemy);
        } else {
            this->move(enemy);
        }
    }

}