#include <cmath>

#include "Point.hpp"

namespace ariel {
    Point::Point() :
            x_coordinate(0),
            y_coordinate(0) {}

    Point::Point(double _x_coordinate, double _y_coordinate) :
            x_coordinate(_x_coordinate),
            y_coordinate(_y_coordinate) {}

    Point::Point(Point const &_other) :
            x_coordinate(_other.x_coordinate),
            y_coordinate(_other.y_coordinate) {}

    Point::Point(Point &&_other) noexcept {}

    Point::~Point() {}

    double Point::distance(const Point &_point2) {
        return sqrt((this->getX() - _point2.getX()) * (this->getX() - _point2.getX()) +
                    (this->getY() - _point2.getY()) * (this->getY() - _point2.getY()));
    }

    std::string Point::print() { return string(*this); }


    Point Point::moveTowards(Point &src, Point &dest, double len) {
        double _dist = src.distance(dest);
        if (_dist <= len) {
            return Point(dest);
        } else {
            Point vec(dest.getX() - src.getX(), dest.getY() - src.getY());
            Point u_vec(vec.getX() / _dist, vec.getY() / _dist);
            return Point(src.getX() + u_vec.getX() * len, src.getY() + u_vec.getY() * len);
        }
    }

    Point &Point::operator=(const Point &_other) {
        return *this;
    }

    Point &Point::operator=(Point &&_other) noexcept {
        this->x_coordinate = _other.getX();
        this->y_coordinate = _other.getY();
        return *this;
    }

    Point::operator std::string() {
        ostringstream s;
        toPrint(s);
        return s.str();
    }

    double Point::getX() const {
        return x_coordinate;
    }

    double Point::getY() const {
        return y_coordinate;
    }

    ostream &Point::toPrint(ostream &output) {
        return output << "(" << this->x_coordinate << "," << this->y_coordinate << ")";
    }

    std::ostream &operator<<(ostream &output, const Point &_point) {
        return output << "(" << _point.x_coordinate << "," << _point.y_coordinate << ")";
    }

    void Point::movePoint(const Point& _other) {
        this->x_coordinate = _other.getX();
        this->y_coordinate = _other.getY();
    }


}