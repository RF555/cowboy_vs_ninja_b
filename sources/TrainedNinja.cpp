#include "TrainedNinja.hpp"

namespace ariel {

    TrainedNinja::TrainedNinja() :
            Ninja(120, 12) {}

    TrainedNinja::TrainedNinja(string name, const Point &point) :
            Ninja(name, point, 120, 12) {}

    TrainedNinja::TrainedNinja(const TrainedNinja &_other) {}

    TrainedNinja::TrainedNinja(TrainedNinja &&_other) noexcept {}

    TrainedNinja::~TrainedNinja() {}

    TrainedNinja &TrainedNinja::operator=(const TrainedNinja &_other) {
        return *this;
    }

    TrainedNinja &TrainedNinja::operator=(TrainedNinja &&_other) noexcept {
        this->setName(_other.getName());
        this->setLives(_other.getLives());
        this->setLocation(_other.getLocation());
        this->setSpeed(_other.getSpeed());
        return *this;
    }

}