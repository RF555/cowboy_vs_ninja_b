#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include <iostream>
#include <string>

#include "Point.hpp"

using namespace std;
namespace ariel {

    enum CharacterType {
        CHARACTER = 0, COWBOY = 1, NINJA = 2
    };


    class Character {
    private:

        Point _location;
        int _lives;
        string _name;
        CharacterType my_type;
        bool team_member;

    protected:
        void setLocation(Point location);

        void setLives(int lives);

        void setName(string name);

        void setMyType(CharacterType myType);

    public:

        Character();

        explicit Character(int lives);

        /**
         * @brief Main Character constructor.
         * @param name String representing the name of the Character.
         * @param point Point as the location of the Character.
         * @param lives Number of lives (hit points) the Character hsa.
         * @param _type enum CharacterType representing the Character's type (Character/Cowboy/Ninja).
         */
        Character(string &name, const Point &point, int lives, CharacterType _type);

        Character(Character const &_other);

        Character(Character &&_other);

        virtual ~Character();


        Character &operator=(const Character &_other);

        Character &operator=(Character &&_other);

        bool operator==(Character &_other);

        friend std::ostream &operator<<(ostream &output, Character &_other);

        /**
         * @return Is the character alive (has more then 0 lives).
         */
        virtual bool isAlive();

        /**
         * @param _other Reference to another character.
         * @return Distance between the 2 characters.
         */
        double distance(Character *_other) const;

        /**
         * @brief Reduces the character's lives by the number of hits.
         * @param hit_points Number of hits.
         * @throws std::invalid_argument If hit_points < 0 (is negative).
         */
        virtual void hit(int hit_points);

        /**
         * @return The name of the character.
         */
        virtual string getName();

        /**
         *
         * @return  A string of the name of the Character, number of lives left AND it's position (as a Point).\n
         *          IF Character is dead ==> the Character's name will be in parenthesis and lives left won't be printed.
         *
         * @details Example (living Character): <name>, 100, (10,3)\n
         *          Example (dead Character): (<name>), (10,3)
         */
        virtual string print();

        virtual explicit operator std::string();

        virtual ostream &toPrint(ostream &output) = 0;

        bool isTeamMember() const;

        void setTeamMember(bool teamMember);

        const Point &getLocation() const;

        int getLives() const;

        CharacterType getMyType() const;

    };

}

#endif
