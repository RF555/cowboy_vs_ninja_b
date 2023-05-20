#include "Team.hpp"
#include <limits>

namespace ariel {

    Team::Team() : _leader(nullptr) {}

    Team::Team(Character *leader) :
            _leader(leader) {
        if (leader->isTeamMember()) {
            throw std::runtime_error("RUNTIME ERROR: Already a team member!\n");
        } else if (this->_leader == nullptr) {
            throw std::runtime_error("RUNTIME ERROR: Leader is nullptr\n");
        } else {
            this->add(leader);
            this->size = 1;
            leader->setTeamMember(true);
        }
    }

    Team::Team(const Team &_other) :
            size(_other.size),
            _leader(_other._leader) {}
//            _cowboys(_other._cowboys),
//            _ninjas(_other._ninjas)

    Team::Team(Team &&_other) noexcept {}

    Team::~Team() {
        /*
         * using map
         */
        for (auto member: this->_members) {
            delete member.second;
        }
        /*
         * using vector
         */
//        for (auto cowboy: this->_cowboys) {
//            delete cowboy;
//        }
//        for (auto ninja: this->_ninjas) {
//            delete ninja;
//        }
    }

    void Team::add(Character *new_member) {
        if (isNotFull()) {
            if (new_member->isTeamMember()) {
                throw std::runtime_error("RUNTIME ERROR: Already a team member!\n");
            }
            /*
             * using map
             */
            if (new_member->getMyType() == COWBOY) { // i+10
                this->_members[this->size + 10] = new_member;
            } else if (new_member->getMyType() == NINJA) { // i+20
                this->_members[this->size + 20] = new_member;
            } else {
                throw std::invalid_argument("INVALID ARGUMENT: Object must be of type Cowboy or Ninja!\n");
            }

            /*
             * using vector
             */
//            if (new_member->getMyType() == COWBOY) {
//                this->_cowboys.push_back(dynamic_cast<Cowboy *>(new_member));
//            } else if (new_member->getMyType() == NINJA) {
//                this->_ninjas.push_back(dynamic_cast<Ninja *>(new_member));
//            } else {
//                throw std::invalid_argument("INVALID ARGUMENT: Object must be of type Cowboy or Ninja!\n");
//            }
            new_member->setTeamMember(true);
            ++this->size;
        } else {
            throw std::runtime_error("RUNTIME ERROR: The team is already full!\n");
        }
    }


    void Team::attack(Team *enemy_team) {
        if (enemy_team == nullptr) {
            throw std::runtime_error("RUNTIME ERROR: Pointer is nullptr!\n");
        }
        if (enemy_team->stillAlive() <= 0) {
            throw std::runtime_error("RUNTIME ERROR: Can not attack an already dead team!\n");
        }
        /*
         * complete the function!
         */

    }

    void Team::chooseNewLeader() {
        if (this->_leader->isAlive()) {
            throw std::runtime_error("RUNTIME ERROR: Can not choose new leader while old leader is alive!\n");
        }
        Character *temp_leader;
        double temp_distance = std::numeric_limits<double>::max();
        /***************
         * Iterate over all our Team members
         ***************/

    }

    Character *Team::chooseVictim(Team *enemy_team) {
        Character *temp_victim;
        double temp_distance = std::numeric_limits<double>::max();
        /***************
         * Iterate over all enemy Team members
         ***************/

        return nullptr;
    }

    void Team::sendAttack(Character *attacker, Character *victim) {

    }


    int Team::stillAlive() {
        int n_alive = 0;
        /***************
         * Iterate over all our Team members
         ***************/
        return n_alive;
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

    bool Team::isNotFull() {
        return this->size < 10;
    }

    Character *Team::getMember(int i) {
        if (this->_members.contains(i)) {
            return this->_members[i];
        } else {
            return nullptr;
        }
    }

}