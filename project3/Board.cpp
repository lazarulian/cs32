#include "Board.h"
#include "Game.h"
#include "globals.h"
#include <iostream>

using namespace std;

// Globals
const int max_rows = 9;
const int max_cols = 9;

class BoardImpl
{
public:
    BoardImpl(const Game& g);
    void clear();
    void block();
    void unblock();
    bool placeShip(Point topOrLeft, int shipId, Direction dir);
    bool unplaceShip(Point topOrLeft, int shipId, Direction dir);
    void display(bool shotsOnly) const;
    bool attack(Point p, bool& shotHit, bool& shipDestroyed, int& shipId);
    bool allShipsDestroyed() const;
    
private:
    // TODO:  Decide what private members you need.  Here's one that's likely
    //        to be useful:
    const Game& m_game;
    char board1[max_rows][max_cols];
    vector<int> idFleet;
};

BoardImpl::BoardImpl(const Game& g)
: m_game(g)
{
    // Filling the Board with Periods
    for (int i = 0; i < m_game.cols(); i++) {
        for (int j = 0; j < m_game.rows(); j++){
            board1[j][i] = '.';
        }
    } // end for loop
    
    // Adding all of the shipID's to the vector
    for (int i = 0; i < m_game.nShips(); i++)
        idFleet.push_back(i);
} // end board implementation constructor

void BoardImpl::clear()
{ // clears the board
    // Filling the Board with Periods
    for (int i = 0; i < m_game.cols(); i++) {
        for (int j = 0; j < m_game.rows(); j++){
            board1[j][i] = '.';
        }
    } // end for loop
}

void BoardImpl::block()
{
    // Block cells with 50% probability
    for (int r = 0; r < m_game.rows(); r++)
        for (int c = 0; c < m_game.cols(); c++)
            if (randInt(2) == 0)
            {
                board1[r][c] = '~';
            }
}

void BoardImpl::unblock()
{ // unblocks the board
    for (int r = 0; r < m_game.rows(); r++)
        for (int c = 0; c < m_game.cols(); c++)
        {
            if (board1[r][c] == '~')
                board1[r][c] = '.';
            else
                continue;
        }
}

bool BoardImpl::placeShip(Point topOrLeft, int shipId, Direction dir)
{
    /////////////////////////////////////////////////////////////////////
    ///Testing the Placement
    ///////////////////////////////////////////////////////////
    // 1. The shipId is invalid
    if (shipId > m_game.nShips()-1) // accessing a ship outside of the range
        return false;
    if (m_game.nShips() == 0) // empty
        return false;
    if (shipId < 0)
        return false;
    
    // Now that we know the ship ID is valid, we can access elements of the ship
    
    int ship_length = m_game.shipLength(shipId);
    char ship_char = m_game.shipSymbol(shipId);
    
    //    2. The ship would be partly or fully outside the board.
    if (m_game.isValid(topOrLeft) == false) // initial test of the point
        return false;
    
    int start_r = topOrLeft.r;
    int start_c = topOrLeft.c;
    
    Point h_end(start_r, start_c+ship_length-1);
    Point v_end(start_r+ship_length-1, start_c);
    
    switch (dir) {
        case HORIZONTAL:
            if (m_game.isValid(h_end) == false)
                return false;
            break;
        case VERTICAL:
            if (m_game.isValid(v_end) == false)
                return false;
            break;
        default:
            return false;
            break;
    }   // end switch statement
    
    // 3. The ship would overlap an already-placed ship.
    // 4. The ship would overlap one or more positions that were blocked by a previous
    //    call to the block function.
    switch (dir) {
        case HORIZONTAL:
            // iterate horizontally from the start point to the end point
            for (int i = start_c; i < ship_length; i++)
            {
                if (board1[start_r][i] != '.')
                    return false;
                else
                    continue;
            }
            break;
        case VERTICAL:
            for (int i = start_r; i < ship_length; i++)
            {
                if (board1[i][start_c] != '.')
                    return false;
                else
                    continue;
            }
            break;
        default:
            return false;
            break;
    }
    
            //    5. The ship with that ship ID has previously been placed on this Board and not
            //    yet been unplaced since its most recent placement.
            
            
            /////////////////////////////////////////////////////////////////////
            ///Placing the Actual Ship
            ///////////////////////////////////////////////////////////
            
            //    bool
    return true;
} // end board implementation

bool BoardImpl::unplaceShip(Point topOrLeft, int shipId, Direction dir)
{
    return false; // This compiles, but may not be correct
}

void BoardImpl::display(bool shotsOnly) const
{
    // This compiles, but may not be correct
}

bool BoardImpl::attack(Point p, bool& shotHit, bool& shipDestroyed, int& shipId)
{
    return false; // This compiles, but may not be correct
}

bool BoardImpl::allShipsDestroyed() const
{
    return false; // This compiles, but may not be correct
}

//******************** Board functions ********************************

// These functions simply delegate to BoardImpl's functions.
// You probably don't want to change any of this code.

Board::Board(const Game& g)
{
    m_impl = new BoardImpl(g);
}

Board::~Board()
{
    delete m_impl;
}

void Board::clear()
{
    m_impl->clear();
}

void Board::block()
{
    return m_impl->block();
}

void Board::unblock()
{
    return m_impl->unblock();
}

bool Board::placeShip(Point topOrLeft, int shipId, Direction dir)
{
    return m_impl->placeShip(topOrLeft, shipId, dir);
}

bool Board::unplaceShip(Point topOrLeft, int shipId, Direction dir)
{
    return m_impl->unplaceShip(topOrLeft, shipId, dir);
}

void Board::display(bool shotsOnly) const
{
    m_impl->display(shotsOnly);
}

bool Board::attack(Point p, bool& shotHit, bool& shipDestroyed, int& shipId)
{
    return m_impl->attack(p, shotHit, shipDestroyed, shipId);
}

bool Board::allShipsDestroyed() const
{
    return m_impl->allShipsDestroyed();
}
