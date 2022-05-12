#include "Board.h"
#include "Game.h"
#include "globals.h"
#include <iostream>
#include <algorithm>
#include <vector>

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
    vector<int> graveyard;
    bool isIDValid(int shipID);
};

BoardImpl::BoardImpl(const Game& g)
: m_game(g)
{
    // Filling the Board with Periods
    for (int i = 0; i < m_game.rows(); i++) {
        for (int j = 0; j < m_game.cols(); j++){
            board1[i][j] = '.';
        }
    } // end for loop
    
    //    // Adding all of the shipID's to the vector
    //    for (int i = 0; i < m_game.nShips(); i++)
    //        idFleet.push_back(i);
    //    cerr << "There are " << idFleet.size() << " ships in the harbor." << endl;
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
    if (shipId >= m_game.nShips()) // accessing a ship outside of the range
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
            // iterate vertically from the start point to the end point
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
    
    vector<int>::iterator shipID_check;
    shipID_check = find(idFleet.begin(), idFleet.end(), shipId);
    if (shipID_check != idFleet.end())
    {
        return false;
    }
    
    /////////////////////////////////////////////////////////////////////
    ///Placing the Actual Ship
    ///////////////////////////////////////////////////////////
    
    int left_r = topOrLeft.r;
    int left_c = topOrLeft.c;
    
    switch (dir)
    {
        case HORIZONTAL:
            for ( int i = left_c; i < (left_c+ship_length); i++)
            {
                board1[left_r][i] = ship_char;
                continue;
            }
            break;
        case VERTICAL:
            for ( int i = left_r; i < (left_r+ship_length); i++)
            {
                board1[i][left_c] = ship_char;
                continue;
            }
            break;
        default:
            break;
    }
    idFleet.push_back(shipId);
    for (int i = 0; i < idFleet.size(); i++)
        cerr << idFleet[i] << ", ";
    cerr << endl;
    return true; // ship was able to be placed
} // end board implementation

bool BoardImpl::unplaceShip(Point topOrLeft, int shipId, Direction dir)
{
    
    int spos_c = topOrLeft.c;
    int spos_r = topOrLeft.r;
    char sym_ship = m_game.shipSymbol(shipId);
    int ship_length = m_game.shipLength(shipId);
    
    // Basic Tests we had already defined
    if (m_game.isValid(topOrLeft) != true)
        return false;
    if (shipId >= m_game.nShips()) // accessing a ship outside of the range
        return false;
    if (m_game.nShips() == 0) // empty
        return false;
    if (shipId < 0)
        return false;
    
    // Testing Whether the last position of the thing is valid
    
    Point h_end(spos_r, spos_c+ship_length-1);
    Point v_end(spos_r+ship_length-1, spos_c);
    
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
    }
    
    //    1. The shipId is invalid - checking whether the ID is in the placed ships vector
    vector<int>::iterator shipID_check;
    shipID_check = find(idFleet.begin(), idFleet.end(), shipId);
    if (shipID_check == idFleet.end())
    {
        return false;
    }
    //    2. The board does not contain the entire ship at the indicated locations.
    
    switch (dir)
    { // checks if the correct symbol is present in all of the places that they are talkinga bout
        case HORIZONTAL:
            for ( int i = spos_c; i < (spos_c+ship_length); i++)
            {
                if (board1[spos_r][i] != sym_ship)
                {
                    return false;
                }
                else
                    continue;
            }
            break;
        case VERTICAL:
            for ( int i = spos_r; i < (spos_r+ship_length); i++)
            {
                if (board1[i][spos_c] != sym_ship)
                    return false;
                else
                    continue;
            }
            break;
        default:
            break;
    }
    /////////////////////////////////////////////
    ///Actually removing the ship
    ////////////////////////////////////////////
    
    int left_r = topOrLeft.r;
    int left_c = topOrLeft.c;
    
    switch (dir)
    {
        case HORIZONTAL:
            for ( int i = left_c; i < (left_c+ship_length); i++)
            {
                board1[left_r][i] = '.';
                continue;
            }
            break;
        case VERTICAL:
            for ( int i = left_r; i < (left_r+ship_length); i++)
            {
                board1[i][left_c] = '.';
                continue;
            }
            break;
        default:
            break;
    }
    
    // Successful ship unplacement
    for (int i = 0; i < idFleet.size(); i++)
    {
        if (idFleet[i] == shipId)
            idFleet.erase(idFleet.begin()+i);
    }
    return true;
}

void BoardImpl::display(bool shotsOnly) const
{
    // Crude Implementation of Display for Testing Purposes
    cout << "  "; // matching the column header
    
    for(int i=0; i < m_game.cols(); i++)
    {
        cout << i;
    }
    cout << '\n';
    // working with the rows
    for(int i = 0; i < m_game.rows(); i++)
    {
        cout << i << " "; // initial 2 spaces for the rows
        for(int j = 0; j < m_game.cols(); j++)
        {
            if(shotsOnly == true)
            {
                if(board1[i][j] != 'X' && board1[i][j] != 'o')
                    cout << "."; // printing hits only
                else
                { // printing hits (default)
                    cout << board1[i][j];
                }
            }
            else
            { // regular board
                cout << board1[i][j];
            }
        }
        cout << '\n';
    } // end for loop
}

bool BoardImpl::attack(Point p, bool& shotHit, bool& shipDestroyed, int& shipId)
{
    //the attack point is outside of the board area, or an attack is made on a previously attacked location
    // Checking if the point is valid
    int a_row = p.r;
    int a_col = p.c;
    
    if (m_game.isValid(p) != true){
        shotHit = false;
        shipDestroyed = false;
        cerr << "Failed because: point invalid" << endl;
        return false;
    }
    
    // Already been hit
    if (board1[a_row][a_col] == 'o' || board1[a_row][a_col] == 'X')
    {
        shotHit = false;
        shipDestroyed = false;
        cerr << "Failed because: already hit" << endl;
        return false;
    }
    
    // Valid Shots
    // hits and misses
    if (board1[a_row][a_col] == '.') {
        board1[a_row][a_col] = 'o'; // changes it
        shotHit = false;
        shipDestroyed = false;
        return true;
    }
    else
    { // actually hits something
        char hitship_symb = board1[a_row][a_col];
        board1[a_row][a_col] = 'X';
        shotHit = true;
        for (int i = 0; i < m_game.rows(); i++)
        {
            if (board1[i][a_col] == hitship_symb)
            {
                shipDestroyed = false;
                return true;
            }
        }
        for (int i = 0; i < m_game.cols(); i++)
        {
            if (board1[a_row][i] == hitship_symb)
            {
                shipDestroyed = false;
                return true;
            }
        }
        
        // Ship Sank
        
        //  If this specific attack destroyed the last undamaged segment of a ship, then the shipDestroyed parameter must be set to true and the shipId parameter must be set to the ship ID of the ship that was destroyed; otherwise the shipDestroyed parameter must be set to false and shipId must be left unchanged.

        
        for (int i = 0; i < m_game.nShips(); i++)
        {
            if (m_game.shipSymbol(i) == hitship_symb)
            {
                shipId = i;
                graveyard.push_back(i);
                break;
            }
        }
    
        shipDestroyed = true;
        return true;
    } // end else
    
    return false;
} // end attack

bool BoardImpl::allShipsDestroyed() const
{
    if (graveyard.size() == m_game.nShips())
        return true;
    else
        return false;
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
