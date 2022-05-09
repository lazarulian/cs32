#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "globals.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cctype>

using namespace std;

class GameImpl
{
  public:
    GameImpl(int nRows, int nCols);
    ~GameImpl();
    int rows() const;
    int cols() const;
    bool isValid(Point p) const;
    Point randomPoint() const;
    bool addShip(int length, char symbol, string name);
    int nShips() const;
    int shipLength(int shipId) const;
    char shipSymbol(int shipId) const;
    string shipName(int shipId) const;
    Player* play(Player* p1, Player* p2, Board& b1, Board& b2, bool shouldPause);
    
private:
    int m_rows;
    int m_cols;
    int numShips;
    struct Ship {
        int id;
        int length;
        string name;
        char symbol;
    };
    vector<Ship*> harbor;
};

void waitForEnter()
{
    cout << "Press enter to continue: ";
    cin.ignore(10000, '\n');
}

GameImpl::GameImpl(int nRows, int nCols) : m_rows(nRows), m_cols(nCols), numShips(0)
{
    // This compiles but may not be correct
}
 // Destructor
GameImpl::~GameImpl()
{
    for (int i = 0; i < numShips; i++)
    {
        delete harbor[i];
    }
//    cerr << "Destructed" << endl;
}

int GameImpl::rows() const
{
    return m_rows;
}

int GameImpl::cols() const
{
    return m_cols;
}

bool GameImpl::isValid(Point p) const
{
    return p.r >= 0  &&  p.r < rows()  &&  p.c >= 0  &&  p.c < cols();
}

Point GameImpl::randomPoint() const
{
    return Point(randInt(rows()), randInt(cols()));
}

bool GameImpl::addShip(int length, char symbol, string name)
{
    ////////////////////////////////////////
    ///Test Cases
    ///////////////////////////////////////

    // Checking Length
    if (length > 5)
        return false;
    if (length < 2)
        return false;
    
    // Checking The Symbol of the Ship
    
    if (isprint(symbol) == 0)
        return false;
    if (symbol == 'X' || symbol == 'o' || symbol == '.')
        return false;
    
    // Checking the Name of the Ship
    if (name.size() == 0 || name.length() == 0)
        return false;
    
    ////////////////////////////////////////
    ///Adding the Ships
    ///////////////////////////////////////
    
    Ship* a;
    a = new Ship;
    a->id = this->numShips;
    a->length = length;
    a->name = name;
    a->symbol = symbol;
    harbor.push_back(a);
    numShips++;
    return true;
} // finish addShip

int GameImpl::nShips() const
{ // returns the number of ships in the game
    return numShips;
}

int GameImpl::shipLength(int shipId) const
{ // returns the length of the ship that is occupied by the shipID
    
    // checking to see if the ship ID exists
    if (shipId > this->nShips()-1)
        return -1;
    else { // return the length of the correct shipID
        return harbor[shipId]->length;
    }
}

char GameImpl::shipSymbol(int shipId) const
{
    // checking to see if the ship ID exists
    if (shipId > this->nShips()-1)
        return 'B';
    else { // return the symbol of the correct shipID
        return harbor[shipId]->symbol;
    }
}

string GameImpl::shipName(int shipId) const
{
    // checking to see if the ship ID exists
    if (shipId > this->nShips()-1)
        return "BADEXCEPTION";
    else { // return the length of the correct shipID
        return harbor[shipId]->name;
    }
}

Player* GameImpl::play(Player* p1, Player* p2, Board& b1, Board& b2, bool shouldPause)
{
    return nullptr;  // This compiles but may not be correct
}

//******************** Game functions *******************************

// These functions for the most part simply delegate to GameImpl's functions.
// You probably don't want to change any of the code from this point down.

Game::Game(int nRows, int nCols)
{
    if (nRows < 1  ||  nRows > MAXROWS)
    {
        cout << "Number of rows must be >= 1 and <= " << MAXROWS << endl;
        exit(1);
    }
    if (nCols < 1  ||  nCols > MAXCOLS)
    {
        cout << "Number of columns must be >= 1 and <= " << MAXCOLS << endl;
        exit(1);
    }
    m_impl = new GameImpl(nRows, nCols);
}

Game::~Game()
{
    delete m_impl;
}

int Game::rows() const
{
    return m_impl->rows();
}

int Game::cols() const
{
    return m_impl->cols();
}

bool Game::isValid(Point p) const
{
    return m_impl->isValid(p);
}

Point Game::randomPoint() const
{
    return m_impl->randomPoint();
}

bool Game::addShip(int length, char symbol, string name)
{
    if (length < 1)
    {
        cout << "Bad ship length " << length << "; it must be >= 1" << endl;
        return false;
    }
    if (length > rows()  &&  length > cols())
    {
        cout << "Bad ship length " << length << "; it won't fit on the board"
             << endl;
        return false;
    }
    if (!isascii(symbol)  ||  !isprint(symbol))
    {
        cout << "Unprintable character with decimal value " << symbol
             << " must not be used as a ship symbol" << endl;
        return false;
    }
    if (symbol == 'X'  ||  symbol == '.'  ||  symbol == 'o')
    {
        cout << "Character " << symbol << " must not be used as a ship symbol"
             << endl;
        return false;
    }
    int totalOfLengths = 0;
    for (int s = 0; s < nShips(); s++)
    {
        totalOfLengths += shipLength(s);
        if (shipSymbol(s) == symbol)
        {
            cout << "Ship symbol " << symbol
                 << " must not be used for more than one ship" << endl;
            return false;
        }
    }
    if (totalOfLengths + length > rows() * cols())
    {
        cout << "Board is too small to fit all ships" << endl;
        return false;
    }
    return m_impl->addShip(length, symbol, name);
}

int Game::nShips() const
{
    return m_impl->nShips();
}

int Game::shipLength(int shipId) const
{
    assert(shipId >= 0  &&  shipId < nShips());
    return m_impl->shipLength(shipId);
}

char Game::shipSymbol(int shipId) const
{
    assert(shipId >= 0  &&  shipId < nShips());
    return m_impl->shipSymbol(shipId);
}

string Game::shipName(int shipId) const
{
    assert(shipId >= 0  &&  shipId < nShips());
    return m_impl->shipName(shipId);
}

Player* Game::play(Player* p1, Player* p2, bool shouldPause)
{
    if (p1 == nullptr  ||  p2 == nullptr  ||  nShips() == 0)
        return nullptr;
    Board b1(*this);
    Board b2(*this);
    return m_impl->play(p1, p2, b1, b2, shouldPause);
}
