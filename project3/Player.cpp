#include "Player.h"
#include "Board.h"
#include "Game.h"
#include "globals.h"
#include <iostream>
#include <string>

using namespace std;

//*********************************************************************
//  AwfulPlayer
//*********************************************************************

class AwfulPlayer : public Player
{
  public:
    AwfulPlayer(string nm, const Game& g);
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit,
                                                bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
  private:
    Point m_lastCellAttacked;
};

AwfulPlayer::AwfulPlayer(string nm, const Game& g)
 : Player(nm, g), m_lastCellAttacked(0, 0)
{}

bool AwfulPlayer::placeShips(Board& b)
{
      // Clustering ships is bad strategy
    for (int k = 0; k < game().nShips(); k++)
        if ( ! b.placeShip(Point(k,0), k, HORIZONTAL))
            return false;
    return true;
}

Point AwfulPlayer::recommendAttack()
{
    if (m_lastCellAttacked.c > 0)
        m_lastCellAttacked.c--;
    else
    {
        m_lastCellAttacked.c = game().cols() - 1;
        if (m_lastCellAttacked.r > 0)
            m_lastCellAttacked.r--;
        else
            m_lastCellAttacked.r = game().rows() - 1;
    }
    return m_lastCellAttacked;
}

void AwfulPlayer::recordAttackResult(Point /* p */, bool /* validShot */,
                                     bool /* shotHit */, bool /* shipDestroyed */,
                                     int /* shipId */)
{
      // AwfulPlayer completely ignores the result of any attack
}

void AwfulPlayer::recordAttackByOpponent(Point /* p */)
{
      // AwfulPlayer completely ignores what the opponent does
}

//*********************************************************************
//  HumanPlayer
//*********************************************************************

bool getLineWithTwoIntegers(int& r, int& c)
{
    bool result(cin >> r >> c);
    if (!result)
        cin.clear();  // clear error state so can do more input operations
    cin.ignore(10000, '\n');
    return result;
}

bool enoughSpace (Board& b, Game& g)
{ // function to check whether the board has enough space to place things in
    int num_ships = g.nShips();
    int ship_space = 0;
    int board_space = g.rows()*g.cols();
    int longest_ship = g.shipLength(0);
    for (int i = 0; i < num_ships; i++)
    {
        ship_space = ship_space + g.shipLength(i);
        if (g.shipLength(i) > longest_ship)
            longest_ship = g.shipLength(i);
        continue;
    }
    
    // Checking Total Area
    if (ship_space > board_space)
        return false;
    
    // Checking Row / Column Lengths
    if (g.rows() < longest_ship && g.cols() < longest_ship)
        return false;
    
    else
        return true;
    
} // end enoughSpace

// Implementation with  Human Player Class
class HumanPlayer : public Player
{
  public:
    HumanPlayer(string nm, const Game& g);
    virtual bool isHuman() const {return true;}
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
  private:
    Point m_lastCellAttacked;
};

bool HumanPlayer::placeShips(Board& b)
{
    //*******************************************//
    // Preliminary Check to see if the ships fit //
    //*******************************************//
    
    int num_ships = game().nShips();
    int ship_space = 0;
    int board_space = game().rows()*game().cols();
    int longest_ship = game().shipLength(0);
    for (int i = 0; i < num_ships; i++)
    {
        ship_space = ship_space + game().shipLength(i);
        if (game().shipLength(i) > longest_ship)
            longest_ship = game().shipLength(i);
        continue;
    }
    
    // Checking Total Area
    if (ship_space > board_space)
        return false;
    
    // Checking Row / Column Lengths
    if (game().rows() < longest_ship && game().cols() < longest_ship)
        return false;
    
    //*******************************************//
    // Prompting the Human to Place the Ships    //
    //*******************************************//

    cout << name() << " the Human must place " << game().nShips() << " ships." << endl;
    // Starting the loop that will basically go over all of the ships in the game and place them manually.
    
    // Taking in the horizontal or vertical dimensions
    for (int i = 0; i < game().nShips(); i++)
    {
        b.display(false);
        char direction = '.';
        while (direction != 'h' || direction != 'v')
        {
            cout << "Enter h or v for direction of " << game().shipName(i) << " (length " << game().shipLength(i) << " ): ";
            cin >> direction;
            cin.ignore(10000, '\n');
            if (direction != 'h' && direction != 'v')
                cout << "Direction must be h or v." << endl;
        }
        
        Direction current_direction;
        if (direction == 'h')
            current_direction = HORIZONTAL;
        else
            current_direction = VERTICAL;
            
        
        // Parsing for the row and the column
        int row = -1;
        int col = -1;
        bool ship_placed = false;
        while (ship_placed != true)
        {
            if (direction == 'h')
                cout << "Enter row and column of leftmost cell (e.g., 3 5): ";
            else
                cout << "Enter row and column of topmost cell (e.g., 3 5): ";
            getLineWithTwoIntegers(row, col);
            Point placement(row, col);
            
            if (b.placeShip(placement, i, current_direction) == true)
                ship_placed = true;
            else
                cout << "The ship can not be placed there." << endl;
        }
    } // end placing loop
    
    
    return true;
}

//typedef AwfulPlayer HumanPlayer;
//*********************************************************************
//  MediocrePlayer
//*********************************************************************

// TODO:  You need to replace this with a real class declaration and
//        implementation.
//typedef AwfulPlayer MediocrePlayer;
// Remember that Mediocre::placeShips(Board& b) must start by calling
// b.block(), and must call b.unblock() just before returning.

//*********************************************************************
//  GoodPlayer
//*********************************************************************

// TODO:  You need to replace this with a real class declaration and
//        implementation.
//typedef AwfulPlayer GoodPlayer;

//*********************************************************************
//  createPlayer
//*********************************************************************

Player* createPlayer(string type, string nm, const Game& g)
{
    static string types[] = {
        "human", "awful", "mediocre", "good"
    };
    
    int pos;
    for (pos = 0; pos != sizeof(types)/sizeof(types[0])  &&
                                                     type != types[pos]; pos++)
        ;
    switch (pos)
    {
      case 0:  return new HumanPlayer(nm, g);
      case 1:  return new AwfulPlayer(nm, g);
//      case 2:  return new MediocrePlayer(nm, g);
//      case 3:  return new GoodPlayer(nm, g);
      default: return nullptr;
    }
}
