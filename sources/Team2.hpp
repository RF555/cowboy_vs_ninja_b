#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "sources/Team.hpp"

using namespace std;
namespace ariel {
    /**
 * Iteration order: FIFO (without distinguishing between cowboys and ninjas)
 */
    class Team2 : public Team {
    public:
        Team2();

        Team2(Character *leader);

        Team2(Character &leader);

        Team2(Team2 const &_other);

        Team2(Team2 &&_other) noexcept;

        ~Team2() override;

        Team2 &operator=(Team2 const &_other);

        Team2 &operator=(Team2 &&_other) noexcept;
    };

}
#endif
