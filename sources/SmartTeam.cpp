#include "SmartTeam.hpp"

namespace ariel {

    SmartTeam::SmartTeam() = default;

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    SmartTeam::SmartTeam(const SmartTeam &_other) {}

    SmartTeam::SmartTeam(SmartTeam &&_other) noexcept {}

    SmartTeam::~SmartTeam() = default;

    SmartTeam &SmartTeam::operator=(const SmartTeam &_other) {
        return *this;
    }

    SmartTeam &SmartTeam::operator=(SmartTeam &&_other) noexcept {
        return *this;
    }

    void SmartTeam::attack_victim(Character *curr_victim, Team *enemy_team) {
        if (this->stillAlive() <= 0) { return; }
        /* first loop for Cowboys */
        for (auto curr_member: this->getMembers()) {
            if (curr_member == nullptr) { return; }

            if (curr_member->isAlive()) {
                curr_victim = smartChooseVictim(enemy_team, curr_member);
                if (curr_victim->isAlive()) {
                    if (auto *curr_cowboy = dynamic_cast<Cowboy *>(curr_member)) {
                        if (curr_cowboy->hasboolets()) {
                            curr_cowboy->shoot(curr_victim);
                        } else {
                            curr_cowboy->reload();
                        }
                    }
                }
            }
        }

        /* second loop for Ninjas */
        for (auto curr_member: this->getMembers()) {
            if (curr_member == nullptr) { return; }

            if (curr_member->isAlive()) {
                curr_victim = smartChooseVictim(enemy_team, curr_member);
                if (curr_victim->isAlive()) {
                    if (auto *curr_ninja = dynamic_cast<Ninja *>(curr_member)) {
                        if (curr_ninja->distance(curr_victim) <= 1) {
                            curr_ninja->slash(curr_victim);
                        } else {
                            curr_ninja->move(curr_victim);
                        }
                    }
                }
            }
        }
    }

    Character *SmartTeam::smartChooseVictim(Team *enemy_team, Character *attacker) {
        Character *new_victim = nullptr;
        double new_distance = std::numeric_limits<double>::max();
        double temp_distance = std::numeric_limits<double>::max();
        int new_hit_points = 1000;
        if (attacker->getMyType() == COWBOY) { // choose victim with the lowest points
            /*
             * Iterate over all enemy Team members
             */
            for (auto temp_victim: enemy_team->getMembers()) {
                if (temp_victim->isAlive()) {
                    if (temp_victim->getLives() < new_hit_points) {
                        new_victim = temp_victim;
                        new_hit_points = temp_victim->getLives();
                    }
                }
            }

        } else if (attacker->getMyType() == NINJA) { // choose the closest victim to the attacker
            /*
             * Iterate over all enemy Team members
             */
            for (auto temp_victim: enemy_team->getMembers()) {
                if (temp_victim->isAlive()) {
                    temp_distance = temp_victim->distance(attacker);
                    if (temp_distance < new_distance) {
                        new_victim = temp_victim;
                        new_distance = temp_distance;
                    }
                }
            }

        }
        return new_victim;
    }
}