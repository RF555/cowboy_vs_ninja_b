#include "Team2.hpp"

namespace ariel {

    Team2::Team2() {}

    Team2::Team2(Character *leader) : Team(leader) {}

    Team2::Team2(Character &leader) {}

    Team2::Team2(const Team2 &_other) {}

    Team2::Team2(Team2 &&_other) noexcept {}

    Team2::~Team2() {}

    Team2 &Team2::operator=(const Team2 &_other) {
        return <#initializer#>;
    }

    Team2 &Team2::operator=(Team2 &&_other) noexcept {
        return <#initializer#>;
    }

    void Team2::add(Character *new_member) {
        Team::add(new_member);
    }

    string Team2::print() {
        return Team::print();
    }
}