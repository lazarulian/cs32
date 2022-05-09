#include "Game.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main()
{
    
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
    
    cout << "Passed all test cases" << endl;
    
    return 0;
}