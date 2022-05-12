#include "Game.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main()
{
    // Testing the Initial Implementation of the Game Class
    Game g(5,3);
    cout << g.rows() << endl;
    cout << g.cols() << endl;
    assert(g.addShip(5, 'A', "nuclear") == true);
    assert(g.nShips() == 1);
    assert(g.addShip(3, 'B', "sub") == true);
    assert(g.addShip(2, 'T', "fardane") == true);
    assert(g.addShip(13, 'X', "twelve") == false);
    assert(g.shipName(0) == "nuclear");
    assert(g.shipSymbol(0) == 'A');
    assert(g.shipName(1) == "sub");
    assert(g.shipSymbol(1) == 'B');
    assert(g.shipSymbol(2) == 'T');
    assert(g.shipName(0) == "nuclear");
    assert(g.shipName(2) == "fardane");
    assert(g.shipLength(0) == 5);
    assert(g.shipLength(1) == 3);
    cout << g.nShips() << endl;
    
    cout << "Passed all test cases for game class" << endl;
    
    // Testing the Implementation of the Board Class
    Board newboard(g);
    newboard.display(false);
    newboard.block();
    cout << endl;
    newboard.display(false);
    newboard.unblock();
    cout << endl;
    newboard.display(false);
    Point n(0, 0);
    Point p(2, 2);
    Point d(13, 3);
    assert(newboard.placeShip(n, 0, HORIZONTAL) == false);
    newboard.clear();
    assert(newboard.placeShip(n, 2, HORIZONTAL) == true);
    assert(newboard.placeShip(n, 1, HORIZONTAL) == false);
    assert(newboard.placeShip(n, 1, HORIZONTAL) == false);
    assert(newboard.unplaceShip(n, 2, HORIZONTAL) == true);
    assert(newboard.unplaceShip(n, 2, HORIZONTAL) == false);
    assert(newboard.placeShip(n, 1, HORIZONTAL) == true);
    assert(newboard.placeShip(n, 1, HORIZONTAL) == false);
    assert(newboard.unplaceShip(n, 1, HORIZONTAL) == true);

    // Place Ship
    assert(newboard.placeShip(p, 0, HORIZONTAL) == false);
    // Unplace Ship
    assert(newboard.unplaceShip(p, 0, HORIZONTAL) == false);
//    assert(newboard.unplaceShip(p, 4, HORIZONTAL) == false);
    // Void Display
    cout << "This display should be empty" << endl;
    newboard.display(false);
    newboard.placeShip(n, 2, HORIZONTAL);
    cout << "This display should have one ship placed on it" << endl;
    newboard.display(false);

    // Attack
    bool hit;
    bool destroyed;
    int shipID;
    assert(newboard.attack(d, hit, destroyed, shipID) == false);
    assert(newboard.attack(p, hit, destroyed, shipID) == true);
    assert(hit == false);
    assert(destroyed == false);

    assert(newboard.attack(n, hit, destroyed, shipID) == true);
    assert(hit == true);
    assert(destroyed == false);

    // Display
    cout << "Displays entire board" << endl;
    newboard.display(false);
    cout << "Displays the board with only hits and misses" << endl;
    newboard.display(true);
    
    // all Ships Destroyed
    assert(newboard.allShipsDestroyed() == false);
    
    
    
    
    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "PASSED ALL TEST CASES" << endl;
    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;

    return 0;
}
