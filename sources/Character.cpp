#include "Character.hpp"

namespace ariel {

    Character::Character() :
            _location(Point()),
            _lives(0),
            _name("None"),
            my_type(CHARACTER),
            team_member(false) {}

    Character::Character(int lives) :
            _location(Point()),
            _lives(lives),
            _name("None"),
            my_type(CHARACTER),
            team_member(false) {}

    Character::Character(string &name, const Point &point, int lives, CharacterType _type) :
            _location(point),
            _lives(lives),
            _name(name),
            my_type(_type),
            team_member(false) {}

    Character::Character(const Character &_other) :
            _location(_other._location),
            _lives(_other._lives),
            _name(_other._name),
            team_member(_other.team_member) {}

    Character::Character(Character &&_other) noexcept {}

    Character::~Character() {}

    Character &Character::operator=(const Character &_other) { return *this; }

    Character &Character::operator=(Character &&_other) noexcept {
        this->_lives = _other.getLives();
        this->_name = _other.getName();
        this->_location = _other.getLocation();
        return *this;
    }

    bool Character::isAlive() { return this->getLives() > 0; }

    double Character::distance(Character *_other) {
        return this->getLocation().distance(_other->getLocation());
    }

    void Character::hit(int hit_points) {
        if (hit_points < 0) {
            throw std::invalid_argument("INVALID ARGUMENT: hit_points mus be positive!\n");
        }
        if (hit_points > this->_lives) {
            this->_lives = 0;
        } else {
            this->_lives -= hit_points;
        }
    }

    string Character::getName() { return this->_name; }

    string Character::print() { return string(*this); }

    Character::operator std::string() {
        ostringstream s;
        toPrint(s);
        return s.str();
    }

    Point &Character::getLocation() const { return _location; }

    int Character::getLives() const { return _lives; }

    std::ostream &operator<<(ostream &output, Character &_other) {
        return _other.toPrint(output);
    }

    void Character::setLocation(const Point &location) {
        this->_location.setX(location.getX());
        this->_location.setY(location.getY());
    }

    void Character::setLives(int lives) { this->_lives = lives; }

    void Character::setName(const string &name) { this->_name = name; }

    bool Character::operator==(Character &_other) { return &(*this) == &_other; }

    void Character::setMyType(CharacterType myType) {
        my_type = myType;
    }

    CharacterType Character::getMyType() const {
        return my_type;
    }

    bool Character::isTeamMember() const {
        return team_member;
    }

    void Character::setTeamMember(bool teamMember) {
        team_member = teamMember;
    }

}