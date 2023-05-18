#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    private:
        int _speed{};

    protected:

        void setSpeed(int speed);

    public:

        Ninja();

        Ninja(int lives, int speed);

        /**
         * @brief Main Ninja constructor.
         * @param name String representing the name of the Character.
         * @param point Point as the location of the Character.
         * @param lives Number of lives (hit points) the Character hsa.
         * @param speed An int representing the Ninja's speed (length it can
         */
        Ninja(const string &name, Point point, int lives, int speed);

        Ninja(Ninja const &_other);

        Ninja(Ninja &&_other) noexcept;

        int getSpeed() const;

        ~Ninja() override;

        Ninja &operator=(const Ninja &_other);

        Ninja &operator=(Ninja &&_other) noexcept;

        /**
         * @brief Moves the ninja towards the enemy the distance equivalent to it's speed.
         * @param enemy Reference of an enemy to move towards to.
         */
        virtual void move(Character *enemy);

        /**
         * @brief Slush the enemy.
         * @param enemy Reference to an enemy.
         * @details If the ninja is alive AND is less then (or equal) 1m from the enemy:\n
         *          subtract 40 lives from the enemy.
         * @details Else do nothing.
         * @throws std::runtime_error If this Ninja is dead OR the enemy is dead.
         */
        virtual void slash(Character *enemy);

        ostream &toPrint(ostream &output) override;

        void attack(Character *enemy) override;
    };

}

#endif
