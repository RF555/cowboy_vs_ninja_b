#include "Team2.hpp"

namespace ariel {

    Team2::Team2() {}

    Team2::Team2(Character *leader) : Team(leader) {}

    Team2::Team2(Character &leader) {}

    Team2::Team2(const Team2 &_other) {}

    Team2::Team2(Team2 &&_other) noexcept {}

    Team2::~Team2() {}

    Team2 &Team2::operator=(const Team2 &_other) {
        return *this;
    }

    Team2 &Team2::operator=(Team2 &&_other) noexcept {
        return *this;
    }

    void Team2::attack(Team *enemy_team) {
        if (enemy_team == nullptr) {
            throw std::invalid_argument("INVALID ARGUMENT: Pointer is nullptr!\n");
        }
        if (enemy_team->stillAlive() <= 0) {
            throw std::runtime_error("RUNTIME ERROR: Can not attack an already dead team!\n");
        }
        if (this->stillAlive() <= 0) {
            throw std::runtime_error("RUNTIME ERROR: Dead team not attack!\n");
        }
        if (!this->_leader->isAlive()) {
            chooseNewLeader();
        }
        Character *curr_victim = chooseVictim(enemy_team);
        for (auto curr_member: this->_members) {
            if (curr_member->isAlive()) {
                if (!this->_leader->isAlive()) {
                    chooseNewLeader();
                    curr_victim = chooseVictim(enemy_team);
                }
                if (!curr_victim->isAlive()) {
                    curr_victim = chooseVictim(enemy_team);
                }
                if (curr_victim != nullptr) {
                    curr_member->attack(curr_victim);
                }
            }
        }
    }


}