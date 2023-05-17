#include "Team.hpp"

namespace ariel {

    Team::Team() {}

    Team::Team(Character *leader) : _leader(leader), size(1) {}

    Team::Team(Character &leader) {}

    Team::Team(const Team &_other) {}

    Team::Team(Team &&_other) noexcept {}

    Team::~Team() {}

    void Team::add(Character *member) {}

    void Team::attack(Team *enemies) {}

    void Team::attack(Team &enemies) {}

    int Team::stillAlive() {
        return 0;
    }

    string Team::print() {
        return std::string();
    }

    Team &Team::operator=(const Team &_other) {
        return *this;
    }

    Team &Team::operator=(Team &&_other) noexcept {
        return *this;
    }

    bool Team::operator==(Team &_other) {
        return &(*this) == &_other;
    }
}