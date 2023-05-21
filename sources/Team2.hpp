#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

using namespace std;
namespace ariel {

    /**
     * Iteration order: FIFO (without distinguishing between cowboys and ninjas)
     */
    class Team2 : public Team {

    protected:
        void attack_victim(Character *curr_victim, Team *enemy_team) override;

    public:

        Team2();

        /**
         * @param leader A pointer to the leader
         * @throws std::runtime_error If the pointer is nullptr.
         * @throws std::runtime_error If the leader already has a team.
         */
        explicit Team2(Character *leader);

        Team2(Team2 const &_other);

        Team2(Team2 &&_other) noexcept;

        ~Team2() override;

        Team2 &operator=(Team2 const &_other);

        Team2 &operator=(Team2 &&_other) noexcept;


    };

}
#endif
