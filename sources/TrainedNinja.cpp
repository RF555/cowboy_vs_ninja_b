#include "TrainedNinja.hpp"

namespace ariel {

    TrainedNinja::TrainedNinja() :
            Ninja(120, 12) {}

    TrainedNinja::TrainedNinja(const string &name, Point point) :
            Ninja(name, point, 120, 12) {}

    TrainedNinja::TrainedNinja(const TrainedNinja &_other) {}

    TrainedNinja::TrainedNinja(TrainedNinja &&_other) noexcept {}

    TrainedNinja::~TrainedNinja() {}

}