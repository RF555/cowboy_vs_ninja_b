#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <vector>

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;
namespace ariel {
    /**
     * Iteration order:
     *      1. all cowboys (FIFO).
     *      2. all ninjas (FIFO).
     */
    class Team {

        int size;
        Character *_leader;
        vector<Character *> members;

//        vector<Cowboy> _cowboys;
//        vector<Ninja> _ninjas;

    public:
        Team();

        Team(Character *leader);

        Team(Character &leader);

        Team(Team const &_other);

        Team(Team &&_other) noexcept;

        virtual ~Team();

        Team &operator=(Team const &_other);

        Team &operator=(Team &&_other) noexcept;

        /**
         * Adds the Character to the team.
         * @param member Reference to a Character.
         */
        virtual void add(Character *member);

        /**
         *
         * @param enemies Pointer to the attacked Team.
         */
        virtual void attack(Team *enemies);

        /**
         *
         * @param enemies Reference to the attacked Team.
         */
        virtual void attack(Team &enemies);

        /**
         * @return The number of members still alive.
         */
        virtual int stillAlive();

        /**
         *
         * @return A string of all members of the team.
         */
        virtual string print();

        bool operator==(Team &_other);

    };

    /**
     * Iteration order: FIFO (without distinguishing between cowboys and ninjas)
     */
    class Team2 : public Team {
    public:
        Team2();

        Team2(Character &leader);

        Team2(Team2 const &_other);

        Team2(Team2 &&_other) noexcept;

        ~Team2() override;

        Team2 &operator=(Team2 const &_other);

        Team2 &operator=(Team2 &&_other) noexcept;
    };

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
#endif //TEAM_HPP
