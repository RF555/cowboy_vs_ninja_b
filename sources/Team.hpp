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
     * @details Iteration order:\n
     *          1. all cowboys (FIFO).\n
     *          2. all ninjas (FIFO).
     */
    class Team {
    private:
        /**
         * @brief Number of team members.
         */
        int size;
        /**
         * @brief  Pointer to the them leader.
         */
        Character *_leader;
        /**
         * @brief Vector of the Cowboy members.
         */
        vector<Cowboy *> _cowboys;
        /**
         * @brief Vector of the Ninja members.
         */
        vector<Ninja *> _ninjas;

    protected:

        /**
         * @brief Choose leader to be the closest member to the old (dead) leader.
         */
        void choose_new_leader();

        /**
         * @brief Choose the closest enemy to our leader to be the victim.
         * @param enemy_team Pointer to the enemy Team.
         * @return Pointer to the chosen victim.
         */
        Character *choose_victim(Team *enemy_team);

        /**
         * @brief Send an attacker on the victim.
         * @param attacker Character from our Team.
         * @param victim Character from enemy Team.
         */
        void send_attack(Character *attacker, Character *victim);

    public:

        Team();

        /**
         * @param leader A pointer to the leader
         * @throws std::runtime_error If the pointer is nullptr.
         * @throws std::runtime_error If the leader already has a team.
         */
        explicit Team(Character *leader);

        Team(Team const &_other);

        Team(Team &&_other) noexcept;

        virtual ~Team();

        Team &operator=(Team const &_other);

        Team &operator=(Team &&_other) noexcept;

        /**
         * @brief Adds the Character to the team.
         * @param new_member Reference to a Character.
         * @throws std::invalid_argument If new_member is not of type Cowboy or Ninja.
         * @throws std::runtime_error If there are already 10 members in the team.
         */
        virtual void add(Character *new_member);

        /**
         * @brief Attack the enemy team.
         * @param enemy_team Pointer to the attacked Team.
         * @details This is how the attack will be launched:\n
         *          1. Check if our leader is alive.\n
         *              * If not - choose a new leader (closest member to it).\n
         *          2. Choose a victim - closest (living) enemy to our leader.\n
         *          3. Attacking team will attack the victim:\n
         *              * Cowboys:\n
         *                  ** If has bullets - shoot.\n
         *                  ** If no bullets left - reload.\n
         *              * Ninjas:\n
         *                  ** If within 1m of the victim - slash.\n
         *                  ** Else - move towards the victim.\n
         *          4. At every stage - if the victim is dead - choose a new victim (same as before).\n
         *          5. Attack ends when:\n
         *              * There are no living members in our group.\n
         *              * There are no living members in the enemy group.
         * @throws std::runtime_error If enemy_team is nullptr.
         * @throws std::runtime_error If enemy_team has no living members.
         */
        virtual void attack(Team *enemy_team);

        /**
         * @return The number of members still alive.
         */
        virtual int stillAlive();

        /**
         * @brief
         * @return A string of all members of the team.
         */
        virtual string print();

        bool operator==(Team &_other);

        /**
         * @return True if the Team LESS than 10 members.
         */
        bool isNotFull();

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
