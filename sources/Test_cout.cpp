#include "../doctest.h"
#include "Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Build Point") {
    Point a;
    CHECK_EQ(a.getX(), 0);
    CHECK_EQ(a.getY(), 0);
    Point b(1.003, 2);
    CHECK_EQ(b.getX(), 1.003);
    CHECK_EQ(b.getY(), 2);
}

TEST_CASE("Points distance") {
    Point a;
    Point b(0, 1);
    CHECK(a.distance(b) == 1);
    CHECK(b.distance(a) == 1);
    Point c(0, 2);
    CHECK(a.distance(c) == 2);
    CHECK(c.distance(a) == 2);
    Point d(0, 3);
    CHECK(a.distance(d) == 3);
    CHECK(d.distance(a) == 3);
    Point e(4, 0);
    CHECK(a.distance(e) == 4);
    CHECK(e.distance(a) == 4);
    Point f(4, 3);
    CHECK(a.distance(f) == 5);
    CHECK(f.distance(a) == 5);
    Point g(3, 4);
    CHECK(a.distance(g) == 5);
    CHECK(g.distance(a) == 5);
}

TEST_CASE("Test Point moveTowards") {
    Point a;
    Point b(0, 1);
    Point c(0, 2);
    Point d(0, 3);
    Point ab05 = moveTowards(a, b, 0.5);
    CHECK_EQ(ab05.getX(), 0);
    CHECK_EQ(ab05.getY(), 0.5);
    Point ab09 = moveTowards(a, b, 0.9);
    CHECK_EQ(ab09.getX(), 0);
    CHECK_EQ(ab09.getY(), 0.9);
    Point ba099 = moveTowards(b, a, 0.99);
    cout << "ba099: " << ba099 << endl;
    CHECK_EQ(ba099.getX(), 0);
//    CHECK_EQ(ba099.getY(), 0.01);
    Point ca08 = moveTowards(c, a, 0.8);
    cout << "ca08: " << ca08 << endl;
    CHECK_EQ(ca08.getX(), 0);
    CHECK_EQ(ca08.getY(), 1.2);
    Point db08 = moveTowards(d, b, 0.8);
    cout << "db08: " << db08 << endl;
    CHECK_EQ(db08.getX(), 0);
    CHECK_EQ(db08.getY(), 2.2);
}

TEST_CASE("Build Cowboy") {
    Cowboy cboy1;
    CHECK_EQ(cboy1.getName(), "None");
    CHECK_EQ(cboy1.getLives(), 110);
    CHECK_EQ(cboy1.getLocation().getX(), 0);
    CHECK_EQ(cboy1.getLocation().getY(), 0);
    CHECK_EQ(cboy1.getNBullets(), 6);
    cboy1.hit(4);
    CHECK_EQ(cboy1.getLives(), 106);
    Cowboy cboy2("Roey", Point(5, 3));
    CHECK_EQ(cboy2.getName(), "Roey");
    CHECK_EQ(cboy2.getLives(), 110);
    CHECK_EQ(cboy2.getLocation().getX(), 5);
    CHECK_EQ(cboy2.getLocation().getY(), 3);
    CHECK_EQ(cboy2.getNBullets(), 6);
    cboy2.hit(4);
    CHECK_EQ(cboy2.getLives(), 106);
    cout << cboy1.print() << endl;
    cout << cboy2 << endl;

}

TEST_CASE("Build YoungNinja") {
    YoungNinja ninj1;
    CHECK_EQ(ninj1.getName(), "None");
    CHECK_EQ(ninj1.getLives(), 100);
    CHECK_EQ(ninj1.getLocation().getX(), 0);
    CHECK_EQ(ninj1.getLocation().getY(), 0);
    CHECK_EQ(ninj1.getSpeed(), 14);
    ninj1.hit(4);
    CHECK_EQ(ninj1.getLives(), 96);
    YoungNinja ninj2("San", Point(5.3, 2.09));
    CHECK_EQ(ninj2.getName(), "San");
    CHECK_EQ(ninj2.getLives(), 100);
    CHECK_EQ(ninj2.getLocation().getX(), 5.3);
    CHECK_EQ(ninj2.getLocation().getY(), 2.09);
    CHECK_EQ(ninj2.getSpeed(), 14);
    ninj2.hit(4);
    CHECK_EQ(ninj2.getLives(), 96);
    cout<<ninj1.print()<<endl;
    cout<<ninj2<<endl;
}

TEST_CASE("Build TrainedNinja") {
    TrainedNinja ninj1;
    CHECK_EQ(ninj1.getName(), "None");
    CHECK_EQ(ninj1.getLives(), 120);
    CHECK_EQ(ninj1.getLocation().getX(), 0);
    CHECK_EQ(ninj1.getLocation().getY(), 0);
    CHECK_EQ(ninj1.getSpeed(), 12);
    ninj1.hit(15);
    CHECK_EQ(ninj1.getLives(), 105);
    TrainedNinja ninj2("San", Point(5.3, 2.09));
    CHECK_EQ(ninj2.getName(), "San");
    CHECK_EQ(ninj2.getLives(), 120);
    CHECK_EQ(ninj2.getLocation().getX(), 5.3);
    CHECK_EQ(ninj2.getLocation().getY(), 2.09);
    CHECK_EQ(ninj2.getSpeed(), 12);
    ninj2.hit(10);
    CHECK_EQ(ninj2.getLives(), 110);
    cout<<ninj1.print()<<endl;
    cout<<ninj2<<endl;
}

TEST_CASE("Build OldNinja") {
    OldNinja ninj1;
    CHECK_EQ(ninj1.getName(), "None");
    CHECK_EQ(ninj1.getLives(), 150);
    CHECK_EQ(ninj1.getLocation().getX(), 0);
    CHECK_EQ(ninj1.getLocation().getY(), 0);
    CHECK_EQ(ninj1.getSpeed(), 8);
    ninj1.hit(15);
    CHECK_EQ(ninj1.getLives(), 135);
    OldNinja ninj2("San", Point(5.3, 2.09));
    CHECK_EQ(ninj2.getName(), "San");
    CHECK_EQ(ninj2.getLives(), 150);
    CHECK_EQ(ninj2.getLocation().getX(), 5.3);
    CHECK_EQ(ninj2.getLocation().getY(), 2.09);
    CHECK_EQ(ninj2.getSpeed(), 8);
    ninj2.hit(10);
    CHECK_EQ(ninj2.getLives(), 140);
    cout<<ninj1.print()<<endl;
    cout<<ninj2<<endl;
}

