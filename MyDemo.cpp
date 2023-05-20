/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point p1(32.3, 44);
    Point p2(1.3, 3.5);
    assert(p1.distance(p2) == p2.distance(p1));
    Cowboy *tom = new Cowboy("Tom", p1);
    OldNinja *sushi = new OldNinja("sushi", p2);

    cout << "initialization:\n";
    cout << tom->print() << endl;
    cout << sushi->print() << endl;

    tom->shoot(sushi);

    cout << "\ntom->shoot(sushi)\n";
    cout << tom->print() << endl;
    cout << sushi->print() << endl;

    sushi->move(tom);

    cout << "\nsushi->move(tom)\n";
    cout << sushi->print() << endl;

    sushi->slash(tom);

    cout << "\nsushi->slash(tom)\n";
    cout << tom->print() << endl;
    cout << sushi->print() << endl;

    Team team_A(tom);
    team_A.add(new YoungNinja("Yogi", Point(64, 57)));

    cout << "team_A:\n" << team_A.print() << endl;

    // Team b(tom); should throw tom is already in team a

    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

    cout << "team_B:\n" << team_B.print() << endl;

    while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0) {
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
    }

    if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
    else cout << "winner is team_B" << endl;

    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}
