#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Team.hpp"

namespace ariel {
    /**
     * Iteration order: ???
     */
    class SmartTeam : public Team {
    public:
        SmartTeam();

        SmartTeam(Character &leader);

        SmartTeam(SmartTeam const &_other);

        SmartTeam(SmartTeam &&_other) noexcept;

        ~SmartTeam() override;

        SmartTeam &operator=(SmartTeam const &_other);

        SmartTeam &operator=(SmartTeam &&_other) noexcept;
    };
}

#endif
