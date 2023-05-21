#include "YoungNinja.hpp"

namespace ariel {

    YoungNinja::YoungNinja() :
            Ninja(100, 14) {}

    YoungNinja::YoungNinja(string name, const Point &point) :
            Ninja(name, point, 100, 14) {}

    YoungNinja::YoungNinja(const YoungNinja &_other) {}

    YoungNinja::YoungNinja(YoungNinja &&_other) noexcept {}

    YoungNinja::~YoungNinja() = default;

    YoungNinja &YoungNinja::operator=(const YoungNinja &_other) {
        return *this;
    }

    YoungNinja &YoungNinja::operator=(YoungNinja &&_other) noexcept {
        this->setName(_other.getName());
        this->setLives(_other.getLives());
        this->setLocation(_other.getLocation());
        this->setSpeed(_other.getSpeed());
        return *this;
    }

}