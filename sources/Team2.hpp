#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

using namespace std;
namespace ariel {

    /**
     * Iteration order: FIFO (without distinguishing between cowboys and ninjas)
     */
    class Team2 : public Team {
    private:

    public:

        Team2();

        Team2(Character *leader);

        Team2(Character &leader);

        Team2(Team2 const &_other);

        Team2(Team2 &&_other) noexcept;

        ~Team2() override;

        Team2 &operator=(Team2 const &_other);

        Team2 &operator=(Team2 &&_other) noexcept;

        /**
         * @brief Adds the Character to the team.
         * @param new_member Reference to a Character.
         * @throws std::invalid_argument If new_member is not of type Cowboy or Ninja.
         * @throws std::runtime_error If there are already 10 members in the team.
         */
        void add(Character *new_member) override;
    };

}
#endif
