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
        /**************
         * using vector
         **************/
        for (auto member: this->_members) {
            delete member;
        }

        /**************
         * using map
         **************/
//        for (auto member: this->_members_map) {
//            delete member.second;
//        }
    }

//    void Team::addMemberAt(Character *new_member, int i_plus) {
//        this->_members_map[this->size + i_plus] = new_member;
//        new_member->setTeamMember(true);
//        ++this->size;
//    }

    void Team::add(Character *new_member) {
        if (this->size >= 10) {
            throw std::runtime_error("RUNTIME ERROR: The team is already full!\n");
        }

        if (new_member->isTeamMember()) {
            throw std::runtime_error("RUNTIME ERROR: Already a team member!\n");
        }

        /***** using vector *****/
        this->_members.push_back(new_member);

        /***** using map    *****/
//        if (new_member->getMyType() == COWBOY) { // i+10
//            this->_members_map[this->size + 10] = new_member;
//        } else if (new_member->getMyType() == NINJA) { // i+20
//            this->_members_map[this->size + 20] = new_member;
//        } else {
//            throw std::invalid_argument("INVALID ARGUMENT: Object must be of type Cowboy or Ninja!\n");
//        }

        new_member->setTeamMember(true);
        ++this->size;
    }


    void Team::attack(Team *enemy_team) {
        if (enemy_team == nullptr) {
            throw std::runtime_error("RUNTIME ERROR: Pointer is nullptr!\n");
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

        /***** using vector *****/
        /* first loop for Cowboys */
        for (auto curr_member: this->_members) {
            if (curr_member->isAlive() && curr_member->getMyType() == COWBOY) {
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
        /* second loop for Ninjas */
        for (auto curr_member: this->_members) {
            if (curr_member->isAlive() && curr_member->getMyType() == NINJA) {
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


        /***** using map    *****/
//        for (auto curr_member: this->_members_map) {
//            if (curr_member.second->isAlive()) {
//                if (!this->_leader->isAlive()) {
//                    chooseNewLeader();
//                    curr_victim = chooseVictim(enemy_team);
//                }
//                if (!curr_victim->isAlive()) {
//                    curr_victim = chooseVictim(enemy_team);
//                }
//                curr_member.second->attack(curr_victim);
//            }
//        }
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
        /***** using vector *****/
        for (auto temp_leader: this->_members) {
            if (temp_leader->isAlive()) {
                temp_distance = temp_leader->distance(this->_leader);
                if (temp_distance < new_distance) {
                    new_leader = temp_leader;
                    new_distance = temp_distance;
                }
            }
        }


        /***** using map    *****/
//        for (auto temp: this->_members_map) {
//            if (temp.second->isAlive()) {
//                temp_distance = temp.second->distance(this->_leader);
//                if (temp_distance < new_distance) {
//                    new_leader = temp.second;
//                    new_distance = temp_distance;
//                }
//            }
//        }


        this->_leader = new_leader;
    }

    Character *Team::chooseVictim(Team *enemy_team) {
        Character *new_victim = nullptr;
        double new_distance = std::numeric_limits<double>::max();
        double temp_distance = std::numeric_limits<double>::max();
        /*
         * Iterate over all enemy Team members
         */
        /***** using vector *****/
        for (auto temp_victim: enemy_team->_members) {
            if (temp_victim->isAlive()) {
                temp_distance = temp_victim->distance(this->_leader);
                if (temp_distance < new_distance) {
                    new_victim = temp_victim;
                    new_distance = temp_distance;
                }
            }
        }


        /***** using map    *****/
//        for (auto temp: enemy_team->getMembers()) {
//            if (temp.second->isAlive()) {
//                temp_distance = temp.second->distance(this->_leader);
//                if (temp_distance < new_distance) {
//                    new_victim = temp.second;
//                    new_distance = temp_distance;
//                }
//            }
//        }
        return new_victim;
    }

    int Team::stillAlive() {
        int n_alive = 0;
        /*
         * Iterate over all our Team members
         */
        /***** using vector *****/
        for (auto member: this->_members) {
            if (member->isAlive()) {
                ++n_alive;
            }
        }
        /***** using map    *****/
//        for (auto member: this->_members_map) {
//            if (member.second->isAlive()) {
//                ++n_alive;
//            }
//        }
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

//    bool Team::isNotFull() const {
//        return this->size < 10;
//    }

    const map<int, Character *> &Team::getMembers() {
        return this->_members_map;
    }

    int Team::getSize() const {
        return size;
    }

    Character *Team::getLeader() const {
        return _leader;
    }

//    void Team::setLeader(Character *leader) {
//        _leader = leader;
//    }

    Team::operator std::string() {
        ostringstream s;
        toPrint(s);
        return s.str();
    }

    std::ostream &Team::toPrint(ostream &output) {
        output << "Team size: " << this->getSize() << "\n";
        /***** using vector    *****/
        for (auto member: this->_members) {
            output << member->print() << "\n";
        }

        /***** using map    *****/
//        for (auto member: this->_members_map) {
//            output << member.second->print() << "\n";
//        }

        return output;
    }

    std::ostream &operator<<(ostream &output, const Team &_team) {
        /***** using vector *****/
        for (auto member: _team._members) {
            output << member->print() << "\n";
        }

        /***** using map    *****/
//        for (auto member: _team._members_map) {
//            output << member.second->print() << "\n";
//        }
        return output;
    }


}