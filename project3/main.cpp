#include "Game.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;


bool addStandardShips(Game& g)
{
//    return g.addShip(2, 'A', "aircraft carrier")  &&
//           g.addShip(2, 'B', "battleship")  &&
//           g.addShip(3, 'D', "destroyer")  &&
//           g.addShip(4, 'S', "submarine")  &&
//           g.addShip(5, 'P', "patrol boat");
    
    return g.addShip(5, 'A', "aircraft carrier")  &&
           g.addShip(4, 'B', "battleship")  &&
           g.addShip(3, 'D', "destroyer")  &&
           g.addShip(3, 'S', "submarine")  &&
           g.addShip(2, 'P', "patrol boat");
}

int main()
{
    const int NTRIALS = 100;

    cout << "Select one of these choices for an example of the game:" << endl;
    cout << "  1.  A mini-game between two mediocre players" << endl;
    cout << "  2.  A mediocre player against a human player" << endl;
    cout << "  3.  A " << NTRIALS
         << "-game match between a mediocre and a good player, with no pauses"
         << endl;
    cout << "Enter your choice: ";
    string line;
    getline(cin,line);
    if (line.empty())
    {
        cout << "You did not enter a choice" << endl;
    }
    else if (line[0] == '1')
    {
        Game g(2, 3);
        g.addShip(2, 'R', "rowboat");
        Player* p1 = createPlayer("mediocre", "Popeye", g);
        Player* p2 = createPlayer("mediocre", "Bluto", g);
        cout << "This mini-game has one ship, a 2-segment rowboat." << endl;
        g.play(p1, p2);
        delete p1;
        delete p2;
    }
    else if (line[0] == '2')
    {
        Game g(10, 10);
        addStandardShips(g);
        Player* p1 = createPlayer("mediocre", "Mediocre Midori", g);
//        Player* p2 = createPlayer("human", "Shuman the Human", g);
//        Player* p1 = createPlayer("awful", "fred", g);
        Player* p2 = createPlayer("human", "Shuman the Human", g);
        g.play(p1, p2);
        delete p1;
        delete p2;
    }
    else if (line[0] == '3')
    {
        int nMediocreWins = 0;

        for (int k = 1; k <= NTRIALS; k++)
        {
            cout << "============================= Game " << k
                 << " =============================" << endl;
            Game g(10, 10);
            addStandardShips(g);
//            Player* p1 = createPlayer("awful", "Awful Audrey", g);
            Player* p1 = createPlayer("good", "Good Greg", g);
            Player* p2 = createPlayer("mediocre", "Mediocre Mimi", g);
            Player* winner = (k % 2 == 1 ?
                                g.play(p1, p2, false) : g.play(p2, p1, false));
            if (winner == p2)
                nMediocreWins++;
            delete p1;
            delete p2;
        }
        cout << "The mediocre player won " << nMediocreWins << " out of "
             << NTRIALS << " games." << endl;
          // We'd expect a mediocre player to win most of the games against
          // an awful player.  Similarly, a good player should outperform
          // a mediocre player.
    }
    else
    {
       cout << "That's not one of the choices." << endl;
    }
}

































//int main()
//{
//    // Testing the Initial Implementation of the Game Class
//    Game g(5,3);
//    cout << g.rows() << endl;
//    cout << g.cols() << endl;
//    assert(g.addShip(5, 'A', "nuclear") == true);
//    assert(g.nShips() == 1);
//    assert(g.addShip(3, 'B', "sub") == true);
//    assert(g.addShip(2, 'T', "fardane") == true);
//    assert(g.addShip(13, 'X', "twelve") == false);
//    assert(g.shipName(0) == "nuclear");
//    assert(g.shipSymbol(0) == 'A');
//    assert(g.shipName(1) == "sub");
//    assert(g.shipSymbol(1) == 'B');
//    assert(g.shipSymbol(2) == 'T');
//    assert(g.shipName(0) == "nuclear");
//    assert(g.shipName(2) == "fardane");
//    assert(g.shipLength(0) == 5);
//    assert(g.shipLength(1) == 3);
//    cout << g.nShips() << endl;
//
//    cout << "Passed all test cases for game class" << endl;
//
//    // Testing the Implementation of the Board Class
//    Board newboard(g);
//    newboard.display(false);
//    newboard.block();
//    cout << endl;
//    newboard.display(false);
//    newboard.unblock();
//    cout << endl;
//    newboard.display(false);
//    Point n(0, 0);
//    Point p(2, 2);
//    Point d(13, 3);
//    assert(newboard.placeShip(n, 0, HORIZONTAL) == false);
//    newboard.clear();
//    assert(newboard.placeShip(n, 2, HORIZONTAL) == true);
//    assert(newboard.placeShip(n, 1, HORIZONTAL) == false);
//    assert(newboard.placeShip(n, 1, HORIZONTAL) == false);
//    assert(newboard.unplaceShip(n, 2, HORIZONTAL) == true);
//    assert(newboard.unplaceShip(n, 2, HORIZONTAL) == false);
//    assert(newboard.placeShip(n, 1, HORIZONTAL) == true);
//    assert(newboard.placeShip(n, 1, HORIZONTAL) == false);
//    assert(newboard.unplaceShip(n, 1, HORIZONTAL) == true);
//
//    // Place Ship
//    assert(newboard.placeShip(p, 0, HORIZONTAL) == false);
//    // Unplace Ship
//    assert(newboard.unplaceShip(p, 0, HORIZONTAL) == false);
////    assert(newboard.unplaceShip(p, 4, HORIZONTAL) == false);
//    // Void Display
//    cout << "This display should be empty" << endl;
//    newboard.display(false);
//    newboard.placeShip(n, 2, HORIZONTAL);
//    cout << "This display should have one ship placed on it" << endl;
//    newboard.display(false);
//
//    // Attack
//    bool hit;
//    bool destroyed;
//    int shipID;
//    assert(newboard.attack(d, hit, destroyed, shipID) == false);
//    assert(newboard.attack(p, hit, destroyed, shipID) == true);
//    assert(hit == false);
//    assert(destroyed == false);
//
//    assert(newboard.attack(n, hit, destroyed, shipID) == true);
//    assert(hit == true);
//    assert(destroyed == false);
//
//    // Display
//    cout << "Displays entire board" << endl;
//    newboard.display(false);
//    cout << "Displays the board with only hits and misses" << endl;
//    newboard.display(true);
//
//    // all Ships Destroyed
//    assert(newboard.allShipsDestroyed() == false);
//
//
//
//
//    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
//    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
//    cout << "PASSED ALL TEST CASES" << endl;
//    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
//    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
//
//
//
//
//    return 0;
//}
