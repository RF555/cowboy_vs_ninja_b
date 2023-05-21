#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Team.hpp"

namespace ariel {
    /**
     * Iteration order: ???
     */
    class SmartTeam : public Team {

    protected:
        void attack_victim(Character *curr_victim, Team *enemy_team) override;

    public:

        SmartTeam();

        /**
         * @param leader A pointer to the leader
         * @throws std::runtime_error If the pointer is nullptr.
         * @throws std::runtime_error If the leader already has a team.
         */
        explicit SmartTeam(Character *leader);

        SmartTeam(SmartTeam const &_other);

        SmartTeam(SmartTeam &&_other) noexcept;

        ~SmartTeam() override;

        SmartTeam &operator=(SmartTeam const &_other);

        SmartTeam &operator=(SmartTeam &&_other) noexcept;
    };
}

#endif
