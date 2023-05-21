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

        if (curr_victim) {
            attack_victim(curr_victim, enemy_team);
        } else {
            return;
        }

//        for (auto curr_member: this->_members) {
//            if (curr_member->isAlive()) {
//                if (!this->_leader->isAlive()) {
//                    chooseNewLeader();
//                    curr_victim = chooseVictim(enemy_team);
//                }
//                if (!curr_victim->isAlive()) {
//                    curr_victim = chooseVictim(enemy_team);
//                }
//                if (curr_victim != nullptr) {
//                    curr_member->attack(curr_victim);
//                }
//            }
//        }
    }

    void Team2::attack_victim(Character *curr_victim, Team *enemy_team) {
        for (auto curr_member: this->_members) {
            if (curr_member == nullptr || curr_victim == nullptr) { return; }

            if (curr_member->isAlive() && curr_victim->isAlive()) {
                if (auto *curr_cowboy = dynamic_cast<Cowboy *>(curr_member)) {
                    if (curr_cowboy->hasboolets()) {
                        curr_cowboy->shoot(curr_victim);
                        if (!curr_victim->isAlive()) {
                            curr_victim = chooseVictim(enemy_team);
                        }
                    } else {
                        curr_cowboy->reload();
                    }
                }
            } else if (curr_member->isAlive() && curr_victim->isAlive()) {
                if (auto *curr_ninja = dynamic_cast<Ninja *>(curr_member)) {
                    if (curr_ninja->distance(curr_victim) <= 1) {
                        curr_ninja->slash(curr_victim);
                        if (!curr_victim->isAlive()) {
                            curr_victim = chooseVictim(enemy_team);
                        }
                    } else {
                        curr_ninja->move(curr_victim);
                    }
                }
            }
        }
    }


}