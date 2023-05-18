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
        vector<Cowboy *> _cowboys;
        vector<Ninja *> _ninjas;

    public:
        Team();

        explicit Team(Character *leader);

        Team(Team const &_other);

        Team(Team &&_other) noexcept;

        virtual ~Team();

        Team &operator=(Team const &_other);

        Team &operator=(Team &&_other) noexcept;

        /**
         * Adds the Character to the team.
         * @param new_member Reference to a Character.
         */
        virtual void add(Character *new_member);

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
