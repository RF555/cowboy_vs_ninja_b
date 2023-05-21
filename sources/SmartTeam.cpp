#include "SmartTeam.hpp"

namespace ariel {

    SmartTeam::SmartTeam() = default;

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {

    }

    SmartTeam::SmartTeam(const SmartTeam &_other) {

    }

    SmartTeam::SmartTeam(SmartTeam &&_other) noexcept {

    }

    SmartTeam::~SmartTeam() = default;

    SmartTeam &SmartTeam::operator=(const SmartTeam &_other) {
        return *this;
    }

    SmartTeam &SmartTeam::operator=(SmartTeam &&_other) noexcept {
        return *this;
    }

    void SmartTeam::attack_victim(Character *curr_victim, Team *enemy_team) {
        Team::attack_victim(curr_victim, enemy_team);
    }
}