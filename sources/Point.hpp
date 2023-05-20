#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace ariel {

    class Point {
    private:
        double x_coordinate, y_coordinate;

        virtual ostream &toPrint(ostream &output);

    public:

        Point();

        Point(double _x_coordinate, double _y_coordinate);

        Point(Point const &_other);

        Point(Point &&_other) noexcept;

        double getX() const;

        double getY() const;

        virtual ~Point();

        /**
         * @param _point2 A point.
         * @return Distance between the 2 points.
         */
        double distance(const Point &_point2);

        /**
         * @return A string of the x and y coordinates inside of parenthesis.
         *      Example: (x,y)
         */
        string print();

        /**
         * @brief Find the closest point to 'dest', that is not further then 'len' from 'src'.
         * @param src Source point.
         * @param dest Destination point.
         * @param len Distance from the source point.
         * @return A point between 'src' and 'dest'.
         * @throws std::invalid_argument If len < 0 (is negative).
         */
        static Point moveTowards(Point &src, Point &dest, double len);

        Point &operator=(Point const &_other);

        Point &operator=(Point &&_other) noexcept;

        explicit operator std::string();

        friend std::ostream &operator<<(ostream &output, const Point &_point);

        /**
         * @brief Change this Point location.
         * @param _other The destination Point.
         */
        void movePoint(const Point& _other);

        void setX(double xCoordinate);

        void setY(double yCoordinate);

    };

}

#endif //POINT_HPP
