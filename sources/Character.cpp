#include "Character.hpp"

namespace ariel {

    Character::Character() :
            _location(Point()),
            _lives(0),
            _name("None") {}

    Character::Character(int lives) :
            _location(Point()),
            _lives(lives),
            _name("None") {}

    Character::Character(const string &name, Point point, int lives) :
            _location(point),
            _lives(lives),
            _name(name) {}

    Character::Character(const Character &_other) :
            _location(_other._location),
            _lives(_other._lives),
            _name(_other._name) {}

    Character::Character(Character &&_other) noexcept {}

    Character::~Character() {}

    Character &Character::operator=(const Character &_other) { return *this; }

    Character &Character::operator=(Character &&_other) noexcept {
        this->_lives = _other.getLives();
        this->_name = _other.getName();
        this->_location = _other.getLocation();
        return *this;
    }

    bool Character::isAlive() { return this->_lives > 0; }

    double Character::distance(Character *_other) {
        return this->getLocation().distance(_other->getLocation());
    }

    void Character::hit(int n) {
        if (n > this->_lives) {
            this->_lives = 0;
        } else {
            this->_lives -= n;
        }
    }

    string Character::getName() { return this->_name; }

    string Character::print() { return string(*this); }

    Character::operator std::string() {
        ostringstream s;
        toPrint(s);
        return s.str();
    }

    Point &Character::getLocation() { return _location; }

    int Character::getLives() const { return _lives; }

    std::ostream &operator<<(ostream &output, Character &_other) {
        return _other.toPrint(output);
    }

    void Character::setLocation(const Point &location) { _location = location; }

    void Character::setLives(int lives) { _lives = lives; }

    void Character::setName(const string &name) { _name = name; }

    bool Character::operator==(Character &_other) { return &(*this) == &_other; }

}