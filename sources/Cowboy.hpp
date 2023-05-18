#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
    private:
        int n_bullets{};

    public:

        Cowboy();

        /**
         * @brief Main Cowboy constructor.
         * @param name String representing the name of the Character.
         * @param point Point as the location of the Character.
         * @details Cowboy is constructed with 6 bullets and 110 lives.
         */
        Cowboy(const string &name, Point point);

        Cowboy(Cowboy const &_other);

        Cowboy(Cowboy &&_other) noexcept;

        ~Cowboy() override;

        Cowboy &operator=(const Cowboy &_other);

        Cowboy &operator=(Cowboy &&_other) noexcept;

        int getNBullets() const;


        /**
         * @brief Shoot the enemy.
         * @param enemy Reference to an enemy.
         * @details If the cowboy is alive AND has bullets left:\n
         *          subtract 10 lives from the enemy.\n
         *          subtract 1 bullet from the cowboy.
         * @details Else do nothing.
         * @throws std::runtime_error If this Cowboy is dead OR the enemy is dead.
         */
        virtual void shoot(Character *enemy);

        /**
         * @return True if the cowboy has bullets left.
         */
        virtual bool hasboolets();

        /**
         * @brief Reloads 6 bullets.
         */
        virtual void reload();

        ostream &toPrint(ostream &output) override;

        void attack(Character *enemy) override;
    };

}

#endif
