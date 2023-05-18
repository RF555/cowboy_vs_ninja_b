#include "Team.hpp"

namespace ariel {

    Team::Team() : _leader(nullptr) {}

    Team::Team(Character *leader) :
            _leader(leader),
            size(1) {
//        if (leader->isTeamMember()) {
//            throw runtime_error("RUNTIME ERROR: Already a team member!\n");
//        } else if (this->_leader == nullptr) {
//            throw runtime_error("RUNTIME ERROR: Leader is nullptr");
//        } else {
//            leader->setTeamMember(true);
//        }
    }

    Team::Team(const Team &_other) :
            size(_other.size),
            _leader(_other._leader),
            members(_other.members) {}

    Team::Team(Team &&_other) noexcept {}

    Team::~Team() {}

    void Team::add(Character *new_member) {}

//    void Team::add(Character *new_member) {
//        if (size >= 10) {
//            throw runtime_error("RUNTIME ERROR: There are 10 members already!\n");
//        } else {
//            if (new_member->getMyType() == COWBOY) {
//                this->_cowboys.push_back(new_member);
//                ++this->size;
//            } else if (new_member->getMyType() == NINJA) {
//
//            }
//        }
//    }

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