#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include "Ninja.hpp"

namespace ariel {
    class TrainedNinja : protected Ninja {
    public:


        TrainedNinja();

        /**
         * @brief Main TrainedNinja constructor.
         * @param name String representing the name of the Character.
         * @param point Point as the location of the Character.
         * @details TrainedNinja is constructed with 12 bullets and 120 lives.
         */
        TrainedNinja(const string &name, Point point);

        TrainedNinja(TrainedNinja const &_other);

        TrainedNinja(TrainedNinja &&_other) noexcept;

        ~TrainedNinja() override;

        TrainedNinja &operator=(const TrainedNinja &_other);

        TrainedNinja &operator=(TrainedNinja &&_other) noexcept;

        void slash(Character *enemy) override;

        void move(Character *enemy) override;
    };

}

#endif
