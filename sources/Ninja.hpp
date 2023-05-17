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

        Ninja(const string &name, Point point, int lives, int speed);

        Ninja(Ninja const &_other);

        Ninja(Ninja &&_other) noexcept;

        int getSpeed() const;

        ~Ninja() override;

        Ninja &operator=(const Ninja &_other);

        Ninja &operator=(Ninja &&_other) noexcept;

        /**
         * Moves the ninja towards the enemy the distance equivalent to it's speed.
         * @param enemy Reference of an enemy to move towards to.
         */
        virtual void move(Character *enemy);

        /**
         * Slush the enemy - IF the ninja is alive AND is less then (or equal) 1m from the enemy:
         *                      subtract 40 lives from the enemy.
         * @param enemy Reference to an enemy.
         */
        virtual void slash(Character *enemy);

        ostream &toPrint(ostream &output) override;

    };

}

#endif
