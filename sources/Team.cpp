#include "Team.hpp"

namespace ariel {

    Team::Team() : _leader(nullptr) {}

    Team::Team(Character *leader) :
            _leader(leader) {
        if (leader->isTeamMember()) {
            throw std::runtime_error("RUNTIME ERROR: Already a team member!\n");
        } else if (this->_leader == nullptr) {
            throw std::runtime_error("RUNTIME ERROR: Leader is nullptr\n");
        } else {
            this->_members.push_back(leader);
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
            delete member;
        }
    }

    void Team::add(Character *new_member) {
        if (this->size >= 10) {
            throw std::runtime_error("RUNTIME ERROR: The team is already full!\n");
        }

        if (new_member->isTeamMember()) {
            throw std::runtime_error("RUNTIME ERROR: Already a team member!\n");
        }
        this->_members.push_back(new_member);
        new_member->setTeamMember(true);
        ++this->size;
    }


    void Team::attack(Team *enemy_team) {
        if (enemy_team == nullptr) {
            throw std::invalid_argument("INVALID ARGUMENT: Pointer to enemy team is nullptr!\n");
        }
        if (this->_leader == nullptr) {
            throw std::invalid_argument("INVALID ARGUMENT: Our leader is nullptr!\n");
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
    }

    void Team::attack_victim(Character *curr_victim, Team *enemy_team) {

        /* first loop for Cowboys */
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
            }
        }

        /* second loop for Ninjas */
        for (auto curr_member: this->_members) {
            if (curr_member == nullptr || curr_victim == nullptr) { return; }

            if (curr_member->isAlive() && curr_victim->isAlive()) {
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
        for (auto temp_leader: this->_members) {
            if (temp_leader->isAlive()) {
                temp_distance = temp_leader->distance(this->_leader);
                if (temp_distance < new_distance) {
                    new_leader = temp_leader;
                    new_distance = temp_distance;
                }
            }
        }
        this->_leader = new_leader;
    }

    Character *Team::chooseVictim(Team *enemy_team) {
        Character *new_victim = nullptr;
        double new_distance = std::numeric_limits<double>::max();
        double temp_distance = std::numeric_limits<double>::max();
        /*
         * Iterate over all enemy Team members
         */
        for (auto temp_victim: enemy_team->_members) {
            if (temp_victim->isAlive()) {
                temp_distance = temp_victim->distance(this->_leader);
                if (temp_distance < new_distance) {
                    new_victim = temp_victim;
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
            if (member->isAlive()) {
                ++n_alive;
            }
        }
        return n_alive;
    }

    string Team::print() {
        cout << *this << endl;
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

    int Team::getSize() const {
        return size;
    }

    Character *Team::getLeader() const {
        return _leader;
    }

    Team::operator std::string() {
        ostringstream s;
        toPrint(s);
        return s.str();
    }

    std::ostream &Team::toPrint(ostream &output) {
        for (auto member: this->_members) {
            output << member->print() << "\n";
        }
        return output;
    }

    std::ostream &operator<<(ostream &output, const Team &_team) {
        for (auto member: _team._members) {
            output << member->print() << "\n";
        }
        return output;
    }

    const vector<Character *> &Team::getMembers() const {
        return _members;
    }


}