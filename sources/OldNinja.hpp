#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"

namespace ariel {
    class OldNinja : public Ninja {
    public:

        OldNinja();

        /**
         * Starts with speed 8 and 150 lives.
         */
        OldNinja(const string &name, Point point);

        OldNinja(OldNinja const &_other);

        OldNinja(OldNinja &&_other) noexcept;

        ~OldNinja() override;

        OldNinja &operator=(const OldNinja &_other);

        OldNinja &operator=(OldNinja &&_other) noexcept;


        void slash(Character *enemy) override;

        void move(Character *enemy) override;

    };

}
#endif
