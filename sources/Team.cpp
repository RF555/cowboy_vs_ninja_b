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

    Team::Team(Team &&_other) noexcept {}

    Team::~Team() {
        for (auto member: this->_members) {
            delete member.second;
        }
    }

    void Team::addMemberAt(Character *new_member, int i_plus) {
        this->_members[this->size + i_plus] = new_member;
        new_member->setTeamMember(true);
        ++this->size;
    }

    void Team::add(Character *new_member) {
        if (this->size >= 10) {
            throw std::runtime_error("RUNTIME ERROR: The team is already full!\n");
        }

        if (new_member->isTeamMember()) {
            throw std::runtime_error("RUNTIME ERROR: Already a team member!\n");
        }

        if (new_member->getMyType() == COWBOY) { // i+10
            this->addMemberAt(new_member, 10);
        } else if (new_member->getMyType() == NINJA) { // i+20
            this->addMemberAt(new_member, 20);
        } else {
            throw std::invalid_argument("INVALID ARGUMENT: Object must be of type Cowboy or Ninja!\n");
        }
    }


    void Team::attack(Team *enemy_team) {
        if (enemy_team == nullptr) {
            throw std::runtime_error("RUNTIME ERROR: Pointer is nullptr!\n");
        }
        if (enemy_team->stillAlive() <= 0) {
            throw std::runtime_error("RUNTIME ERROR: Can not attack an already dead team!\n");
        }
        if (!this->_leader->isAlive()) {
            chooseNewLeader();
        }
        Character *curr_victim = chooseVictim(enemy_team);
        for (auto curr_member: this->_members) {
            if (curr_member.second->isAlive()) {
                if (!this->_leader->isAlive()) {
                    chooseNewLeader();
                    curr_victim = chooseVictim(enemy_team);
                }
                if (!curr_victim->isAlive()) {
                    curr_victim = chooseVictim(enemy_team);
                }
                curr_member.second->attack(curr_victim);
            }
        }
    }

    void Team::chooseNewLeader() {
        if (this->_leader->isAlive()) {
            throw std::runtime_error("RUNTIME ERROR: Can not choose new leader while old leader is alive!\n");
        }
        Character *new_leader = nullptr;
        double new_distance = std::numeric_limits<double>::max();
        double temp_distance = std::numeric_limits<double>::max();
        /*
         * Iterate over all our Team members
         */
        for (auto temp: this->_members) {
            if (temp.second->isAlive()) {
                temp_distance = temp.second->distance(this->_leader);
                if (temp_distance < new_distance) {
                    new_leader = temp.second;
                    new_distance = temp_distance;
                }
            }
        }
        this->setLeader(new_leader);
    }

    Character *Team::chooseVictim(Team *enemy_team) {
        Character *new_victim = nullptr;
        double new_distance = std::numeric_limits<double>::max();
        double temp_distance = std::numeric_limits<double>::max();
        /*
         * Iterate over all enemy Team members
         */
        for (auto temp: enemy_team->getMembers()) {
            if (temp.second->isAlive()) {
                temp_distance = temp.second->distance(this->_leader);
                if (temp_distance < new_distance) {
                    new_victim = temp.second;
                    new_distance = temp_distance;
                }
            }
        }
        return new_victim;
    }

    int Team::stillAlive() {
        int n_alive = 0;
        /*
         * Iterate over all our Team members
         */
        for (auto member: this->_members) {
            if (member.second->isAlive()) {
                ++n_alive;
            }
        }
        return n_alive;
    }

    string Team::print() {
        return string(*this);
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

    bool Team::isNotFull() const {
        return this->size < 10;
    }

    const map<int, Character *> &Team::getMembers() {
        return this->_members;
    }

    int Team::getSize() const {
        return size;
    }

    Character *Team::getLeader() const {
        return _leader;
    }

    void Team::setLeader(Character *leader) {
        _leader = leader;
    }

    Team::operator std::string() {
        ostringstream s;
        toPrint(s);
        return s.str();
    }

    std::ostream &Team::toPrint(ostream &output) {
        output << "Team size: " << this->getSize() << "\n";
        for (auto member: this->_members) {
            output << member.second->print() << "\n";
        }
        return output;
    }

    std::ostream &operator<<(ostream &output, const Team &_team) {
        for (auto member: _team._members) {
            output << member.second << "\n";
        }
        return output;
    }


}