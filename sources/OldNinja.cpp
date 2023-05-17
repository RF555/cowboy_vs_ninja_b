#include "OldNinja.hpp"

namespace ariel {

    OldNinja::OldNinja() :
            Ninja(150, 8) {}

    OldNinja::OldNinja(const string &name, Point point) :
            Ninja(name, point, 150, 8) {}

    OldNinja::OldNinja(const OldNinja &_other) {}

    OldNinja::OldNinja(OldNinja &&_other) noexcept {}

    OldNinja::~OldNinja() {}

    OldNinja &OldNinja::operator=(const OldNinja &_other) { return *this; }

    OldNinja &OldNinja::operator=(OldNinja &&_other) noexcept {
        this->setName(_other.getName());
        this->setLives(_other.getLives());
        this->setLocation(_other.getLocation());
        this->setSpeed(_other.getSpeed());
        return *this;
    }

    void OldNinja::slash(Character *enemy) {}

    void OldNinja::move(Character *enemy) {}
}