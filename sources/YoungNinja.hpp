#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include "Ninja.hpp"

namespace ariel {
    class YoungNinja : public Ninja {
    public:

        YoungNinja();

        /**
         * @brief Main YoungNinja constructor.
         * @param name String representing the name of the Character.
         * @param point Point as the location of the Character.
         * @details YoungNinja is constructed with 14 bullets and 100 lives.
         */
        YoungNinja(string name, const Point &point);

        YoungNinja(YoungNinja const &_other);

        YoungNinja(YoungNinja &&_other) noexcept;

        ~YoungNinja() override;

    };

}

#endif
