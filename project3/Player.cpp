#include "Player.h"
#include "Board.h"
#include "Game.h"
#include "globals.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stack>
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
    HumanPlayer(string nm, const Game& g) : Player(nm, g) {} // constructor - done
    virtual ~HumanPlayer() {}
    virtual bool isHuman() const {return true;} // specifies is human for game implementation - done
    virtual bool placeShips(Board& b); // done
    virtual Point recommendAttack(); // done
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId); // done
    virtual void recordAttackByOpponent(Point p); // done
};

// Constructor
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
            if (!getLineWithTwoIntegers(row, col))
            {
                cout << "You must enter two integers." << endl;
                continue;
            }
            Point placement(row, col);
            if (b.placeShip(placement, i, current_direction) == true)
                ship_placed = true;
            else
                cout << "The ship can not be placed there." << endl;
        }
    } // end placing loop
    
    return true;
}

Point HumanPlayer::recommendAttack()
{ // will recommend the attack for the humanplayer class
    Point recommended_attack;
    int row;
    int col;
    
    cout<<"Enter row and column of leftmost cell (e.g. 3 5): ";
    
    while(!getLineWithTwoIntegers(row, col))
    { // While Loop to get the data for the thing.
        cout<<"You must enter two integers."<<endl;
        cout<<"Enter row and column of leftmost cell (e.g. 3 5): "; //reprompt coordinates
    }
    
    // Initializing Point
    recommended_attack.r = row;
    recommended_attack.c = col;
    return recommended_attack;
}

void HumanPlayer::recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId)
{
    // unnecessary for human
}

void HumanPlayer::recordAttackByOpponent(Point p)
{
    // unnecessary for human
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


class MediocrePlayer : public Player
{
    
public:
    MediocrePlayer(string nm, const Game& g);
    virtual ~MediocrePlayer() {}
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
    
private:
    struct shipHits
    {
        Point hit_loc;
        int m_rowcross[4];
        int m_colcross[4];
    };
    int m_state;
    Point state2;
    Point m_lastCellAttacked;
    bool recursive_placing(Board& b, int ships_placed);
    vector<Point> hit_cells;
    
//    int cross_Radius;
};

MediocrePlayer::MediocrePlayer(string nm, const Game& g) : Player(nm, g), m_state(1) {}

bool MediocrePlayer::recursive_placing(Board &b, int ships_placed)
{ // will recursively place a ship using backtracking to keep starting similar to Djikstras Algorithm
    
    // DATA STRUCTURE / LOCAL VARIABLE IMPLEMENTATIONS
    vector<Point> bad_location; // used so that it doesnt reduntantly choose the same location
    int num_cols = game().cols();
    int num_rows = game().rows();
    
    // BASE CASE
    if (ships_placed == game().nShips())
        return true;
    
    // RECURSIVE STEP
    
    // Initial Loop through the Board to find a place to place the ships
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        { // Iterating through the points to test if the location works
            bool check_bad = false;
            Point to_place(i, j);
            vector<Point>::iterator it;
            for (it = bad_location.begin(); it != bad_location.end(); it++)
            {
                if (to_place.r == it->r && to_place.c == it->c) // checks both row and column
                {
                    check_bad = true; // BAD
                }
            } // looping through the bad locations
            
            
            if (check_bad == false && // test to place the ships down below
                (b.placeShip(to_place, ships_placed, VERTICAL) ||
                 b.placeShip(to_place, ships_placed, HORIZONTAL)))
            { // IS THE SHIP GOING TO BE PLACED PROPRLY
                if (recursive_placing(b, 1+ships_placed))
                {
                    if(b.unplaceShip(to_place, ships_placed, VERTICAL) == false) // backtracking
                    { // alterante option to unplace if it is not the vertical one
                        b.unplaceShip(to_place, ships_placed, HORIZONTAL); // backtracking
                    }
                    bad_location.push_back(to_place);
                    i=0;
                    j=0;
                }
                else
                    return true; // placed
            }// end if for the successful place
        } //col loop
    } // row loop
    
    return false; // recursive catch all
}


 bool MediocrePlayer::placeShips(Board& b)
{ // tries to place the ships 50 times, if it does not work, will return false
     
     for (int i = 0; i < 50; i++)
     {
         b.block();
         
         if (recursive_placing(b, 0) == true)
         { // iterations of the recursive placing algorithm
             b.unblock();
             return true;
         }
     }
     return false;
}

bool isCross(int rowcol, int rowcol2)
{
    if (abs(rowcol - rowcol2) <= 4)
        return true;
    else
        return false;
}

Point MediocrePlayer::recommendAttack()
{
    Point r_p; // random point
    // STATE 1: DORMANT STATE WITHOUT TARGETTED ATTACK
    if(m_state == 1)
    {
        // INITIALLY SETS THE ALREADY ATTACKED FUNCTION
        bool already_attacked = false;
        do {
            already_attacked = false;
            // setting a random point to test the attack (uninformed attack)
            r_p = game().randomPoint();
            vector<Point>::iterator it;
            for(it = hit_cells.begin(); it != hit_cells.end(); it++){
                if(r_p.r == it->r && r_p.c == it->c) {
                    already_attacked = true;
                }
            }
        } while (already_attacked == true);
        return r_p; // return random point
    }
    else
    { // attack state :) GOOD LUCK
        bool already_attacked = false; // same as last time
        bool inCross = false;
        
        do
        {
            already_attacked = false;
            inCross = false;
            
            r_p = game().randomPoint();
            for(int r=0; r<hit_cells.size(); r++){ //if point is in attacked cell set pInhit_cells to true
                if(r_p.r == hit_cells[r].r && r_p.c == hit_cells[r].c)
                    already_attacked = true;
            }
            if(((isCross(m_lastCellAttacked.r, r_p.r) == true && m_lastCellAttacked.c == r_p.c)) ||
               (isCross(m_lastCellAttacked.c, r_p.c) == true && m_lastCellAttacked.r == r_p.r))
            { // is the attack point within the cross
                inCross = true;
            }
        } while (already_attacked || inCross == false);
        return r_p;
    }
    return r_p;
}


bool areEquivalent(int one, int two)
{
    if (one == two)
        return true;
    else
    {
        return false;
    }
}

void MediocrePlayer::recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipID)
{ // WILL SELECT ONE OF THE THREE STATES THAT ARE SPECIFIED IN THE SPECIFICATIONS
    
    // Processing Basic Things for the attack
    if (validShot == false) // should not return false
        return;
    
    // Modifying the Attacked Cells
    hit_cells.push_back(p);
    
    // Processing During the Dormant State (Attack Failed or Missed)
    
    if (m_state == 1)
    {
        // lucky hit! ;)
        if (shipDestroyed == true)
        {
            cerr << "Ship was destroyed randomly" << endl;
            return;
        }
        
        if (shotHit == false)
            return; // stays dormant as nothing changes
        
        if (shotHit == true && shipDestroyed == false) {
            m_state = 2;
            m_lastCellAttacked = p;
            return;
        }
        else{
            return;
        }
    } // state 1 ends
    
    if(m_state == 2)
    { //state 2
//        bool cross_completed = false;
//        bool cross_attacked = false;
//        vector<Point>::iterator it;
//        for(it = hit_cells.begin(); it != hit_cells.end(); it++)
//        {
//            if ((it->c == m_lastCellAttacked.c + i) && (it->r == m_lastCellAttacked.r))
//            {
//                cross_attacks++;
//            }
//        }
//    }
        int cross_attacks = 0;
        int biggestPossibleCross = 0;
        
        for(int i=-4; i<5; i++)
        { //checking columns of cross for already attacked cells
            // Checking the Validity of the Cell for Bad Access
            Point c(m_lastCellAttacked.r, m_lastCellAttacked.c+i);
            if(game().isValid(c))
                biggestPossibleCross++;
            
            // Setting up Iterator for the Cross Configuration
            vector<Point>::iterator it;
            for(it = hit_cells.begin(); it != hit_cells.end(); it++)
            {
                cerr << "Checking and itterating through" << endl;
                if ((it->c == m_lastCellAttacked.c + i) && (it->r == m_lastCellAttacked.r))
                {
                    cross_attacks++;
                }
            }
        }
        
        for(int i=-4; i<5; i++)
        { //checking rows of cross for already attacked cells
            
            // Checking the Validity of the Cell for Bad Access
            Point r(m_lastCellAttacked.r + i, m_lastCellAttacked. c);
            if(game().isValid(r))
                biggestPossibleCross++;
            
            // Setting up Iterator for the Cross Configuration
            vector<Point>::iterator it;
            for(it = hit_cells.begin(); it != hit_cells.end(); it++)
            {
                if((it->r == m_lastCellAttacked.r + i) && (it->c == m_lastCellAttacked.c))
                    cross_attacks++;
            }
        }
        
//        if(areEquivalent(cross_attacks, cross_Radius))
//        { // this is if the cross is the largest, then you will have
//            // to default to (shipsize greater 6) and stop attacks
//            m_state = 1; // back to dormancy
//            return;
//        }
        
        if(areEquivalent(cross_attacks, biggestPossibleCross))
        { // this is if the cross is the largest, then you will have
            // to default to (shipsize greater 6) and stop attacks
            m_state = 1; // back to dormancy
            return;
        }
        
        
        if(shotHit == false)
            return; // continue attack mode
        
        else
        { // will test for ship destruction
            if(shipDestroyed == true)
            {
                m_state = 1; // back to dormancy
                cerr << "Ship was destroyed" << endl;
                return;
            }
            else
                return; // stays in attack mode
        }
        
    }
} // end recordAttackResult

void MediocrePlayer::recordAttackByOpponent(Point p)
{
    // not utilizied by the MediocrePlayer
}




//*********************************************************************
//  GoodPlayer
//*********************************************************************

// TODO:  You need to replace this with a real class declaration and
//        implementation.
//typedef AwfulPlayer GoodPlayer;

void removePoint(Point p, vector<Point>& v)
{
    auto it = v.begin();
    for (; it != v.end(); )
    {
        if (it->r == p.r && it->c == p.c)
            it = v.erase(it);
        else
            it++;
    }
}

class GoodPlayer : public Player
{
public:
    GoodPlayer(string nm, const Game& g);
    virtual ~GoodPlayer() {}
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p) { }
    
    void addAttackPoints(Point p);
    
private:
    vector<Point> m_points;
    int m_state;
    // Stack storing the points surrounding a hit attack
    stack<Point> m_attackPoints;
    // Stores history of shots -- misses and hits
    vector<vector<char>> m_hist;
};

GoodPlayer::GoodPlayer(string nm, const Game& g)
: Player(nm, g), m_state(1)
{
    m_hist.resize(game().rows());
    for (int r = 0; r < game().rows(); r++)
    {
        m_hist[r].resize(game().cols());
        for (int c = 0; c < game().cols(); c++)
        {
            m_points.push_back(Point(r,c));
            m_hist[r][c] = '.';
        }
    }
}

bool GoodPlayer::placeShips(Board& b)
{
    int id = 0;
    bool valid;
    int shipsLeft = game().nShips();
    while (shipsLeft > 0)
    {
        int size = static_cast<int>(m_points.size());
        int i = randInt(size);
        Point p(m_points[i].r, m_points[i].c);
        valid = b.placeShip(p, id, HORIZONTAL);
        if (!valid)
            valid = b.placeShip(p, id, VERTICAL);
        if (valid)
        {
            removePoint(p, m_points);
            shipsLeft--;
            id++;
        }
    }
    // Once ships are placed clear points and reinitiate them for attacking phase
    m_points.clear();
    for (int r = 0; r < game().rows(); r++)
        for (int c = 0; c < game().cols(); c++)
            m_points.push_back(Point(r,c));
    return true;
}

Point GoodPlayer::recommendAttack()
{
    // Randomly select one of the points left
    if (m_state == 1)
    {
        // Randomly select point from points
        int size = static_cast<int>(m_points.size());
        int i = randInt(size);
        Point p(m_points[i].r, m_points[i].c);
        // Remove the selected point from points remaining
        removePoint(p, m_points);
        return p;
    }
    // Attack the next point on the stack
    else // m_state == 2
    {
        Point attack;
        if (!m_attackPoints.empty())
            attack = m_attackPoints.top();
        // Make sure stack is not empty
        else
            cerr << "Error GoodPlayer::reccomendAttack -- stack should not be empty" << endl;
        m_attackPoints.pop();
        // Remove the selected point from points remaining
        removePoint(attack, m_points);
        return attack;
    }
}

void GoodPlayer::recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId)
{
    // Check if shot was valid
    if (!validShot)
        cerr << "Error GoodPlayer::recordAttackResult -- computer should not be shooting invalid shots" << endl;
    
    // If shot hit mark it and add to the stack
    if (shotHit)
    {
        m_hist[p.r][p.c] = 'X';
        addAttackPoints(p);
    }
    // Mark if shot did not hit
    else
        m_hist[p.r][p.c] = 'o';
    
    // Switch to state 2 if shot hit
    if (m_state == 1)
    {
        if (shotHit) m_state = 2;
    }
    // Switch to state 1 if stack is empty
    else // m_state == 2
    {
        if (m_attackPoints.empty())
            m_state = 1;
    }
}

void GoodPlayer::addAttackPoints(Point p)
{
    // If cell above p is valid add it to the stack
    if (p.r-1 >= 0 && m_hist[p.r-1][p.c] == '.')
    {
        m_hist[p.r-1][p.c] = 'a';
        m_attackPoints.push(Point(p.r-1, p.c));
    }
    // If cell below p is valid add it to the stack
    if (p.r+1 <= game().rows()-1 && m_hist[p.r+1][p.c] == '.')
    {
        m_hist[p.r+1][p.c] = 'a';
        m_attackPoints.push(Point(p.r+1, p.c));
    }
    // If cell to the left of p is valid add it to the stack
    if (p.c-1 >= 0 && m_hist[p.r][p.c-1] == '.')
    {
        m_hist[p.r][p.c-1] = 'a';
        m_attackPoints.push(Point(p.r, p.c-1));
    }
    // If cell to the right of p is valid add it to the stack
    if (p.c+1 <= game().cols()-1 && m_hist[p.r][p.c+1] == '.')
    {
        m_hist[p.r][p.c+1] = 'a';
        m_attackPoints.push(Point(p.r, p.c+1));
    }
}



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
      case 2:  return new MediocrePlayer(nm, g);
      case 3:  return new GoodPlayer(nm, g);
      default: return nullptr;
    }
}
