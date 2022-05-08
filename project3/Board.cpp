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
    char board2[max_rows][max_cols];
};

BoardImpl::BoardImpl(const Game& g)
 : m_game(g)
{
    // Filling the Board with Periods
    for (int i = 0; i < m_game.cols(); i++) {
        for (int j = 0; j < m_game.rows(); j++){
            board1[j][i] = '.';
            board2[j][i] = '.';
        }
    } // end for loop
}

void BoardImpl::clear()
{
    // Filling the Board with Periods
    for (int i = 0; i < m_game.cols(); i++) {
        for (int j = 0; j < m_game.rows(); j++){
            board1[j][i] = '.';
            board2[j][i] = '.';
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
                board2[r][c] = '~';
                ; // TODO:  Replace this with code to block cell (r,c)
            }
}

void BoardImpl::unblock()
{ // unblocks the board
    for (int r = 0; r < m_game.rows(); r++)
        for (int c = 0; c < m_game.cols(); c++)
        {
            if (board1[r][c] == '~')
                board1[r][c] = '.';
            if (board2[r][c] == '~')
                board2[r][c] = '.';
            else
                continue;
            ; // TODO:  Replace this with code to unblock cell (r,c) if blocked
        }
}

bool BoardImpl::placeShip(Point topOrLeft, int shipId, Direction dir)
{
    // ShipID Inavlid
    
    
    return false; // This compiles, but may not be correct
}

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
