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

    void Team2::add(Character *new_member) {
        if (isNotFull()) {
            if (new_member->isTeamMember()) {
                throw std::runtime_error("RUNTIME ERROR: Already a team member!\n");
            }
            if (new_member->getMyType() == CHARACTER) {
                throw std::invalid_argument("INVALID ARGUMENT: Object must be of type Cowboy or Ninja!\n");
            } else {
                this->addMemberAt(new_member, 0);
            }
            new_member->setTeamMember(true);
        } else {
            throw std::runtime_error("RUNTIME ERROR: The team is already full!\n");
        }
    }

}