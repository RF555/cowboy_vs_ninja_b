#include "OldNinja.hpp"

namespace ariel {

    OldNinja::OldNinja() :
            Ninja(150, 8) {}

    OldNinja::OldNinja(string name, const Point &point) :
            Ninja(name, point, 150, 8) {}

    OldNinja::OldNinja(const OldNinja &_other) {}

    OldNinja::OldNinja(OldNinja &&_other) noexcept {}

    OldNinja::~OldNinja() {}

}