////////////////////////////////////////////////////////////////////////////////////////////////////////
// APURVA SHAH 705595011 - SMALLBERG SPRING 2022
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Player.h"
#include "Board.h"
#include "Game.h"
#include "globals.h"
#include <iostream>
#include <string>
#include <vector>
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
        cin.clear();
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
        while (direction != 'h' && direction != 'v')
        {
            cout << "Enter h or v for direction of " << game().shipName(i) << " (length " << game().shipLength(i) << " ): ";
            cin >> direction;
            cin.ignore(10000, '\n');
            cin.clear();
            if (direction != 'h' && direction != 'v') {
                cout << "Direction must be h or v." << endl;
                continue;
            }
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

//*********************************************************************
//  MediocrePlayer
//*********************************************************************

class MediocrePlayer : public Player
{
public:
    MediocrePlayer(string nm, const Game& g) : Player(nm, g), m_state(1){}
    ~MediocrePlayer() {}
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
    
private:
    
    int m_state;
    Point activated_point;
    bool recursive_placing(Board &b, int numShips);
    vector<Point> attackedCells;
    
};

bool MediocrePlayer::recursive_placing(Board &b, int numShips)
{ // will recursively place a ship using backtracking to keep starting similar to maze path backtracking
    
    // DATA STRUCTURE / LOCAL VARIABLE IMPLEMENTATIONS
    vector<Point> bad_locations; // used so that it doesnt reduntantly choose the same location

    // BASE CASE
    if(numShips == game().nShips())
        return true;
    
    // RECURSIVE STEP

    // Initial Loop through the Board to find a place to place the ships
    for(int i = 0; i < game().rows(); i++)
    { // first loop row
        for(int j = 0; j < game().cols(); j++)
        { // second loop col
            Point p(i, j);
            bool check_bad = false;
            
            for(int r = 0; r < bad_locations.size(); r++)
            {
                if(p.r == bad_locations[r].r && p.c == bad_locations[r].c)
                {
                    check_bad = true;
                }
            } // looping through the bad locations
            

            if(check_bad == false && (b.placeShip(p, numShips, HORIZONTAL) || b.placeShip(p, numShips, VERTICAL))) // test to place the ships down below
            { // successful placement of ship
                if(recursive_placing(b, numShips + 1) == false)
                {
                    // doesnt work for unplacing ships
                    if(b.unplaceShip(p, numShips, HORIZONTAL) == false)
                       {
                           b.unplaceShip(p, numShips, VERTICAL);
                       }
                    bad_locations.push_back(p);
                    i=0;
                    j=0;
                }
                
                else
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool MediocrePlayer::placeShips(Board &b)
{ // returns true if placed, will place the things around 50 times.
    for(int i = 0; i < 50; i++)
    {
        // intial blocking of board
        b.block();
        
        if(recursive_placing(b, 0) == true)
        { // recursive call
            b.unblock(); // unblock if true since placed
            return true;
        }
        
        // unblocking board if failed for another attempt
        b.unblock();
    }
    return false;
}


Point MediocrePlayer::recommendAttack()
{
    Point p;
    
    
    // INITIAL STATE THAT DECLARES DORMANCY
    
    if(m_state == 1)
    { // will choose a random point to attack since it is in state 1
        bool already_attackedp = false;
        do {
            already_attackedp = false;
            p = game().randomPoint();
            for(int r = 0; r < attackedCells.size(); r++)
            {
                if (p.r == attackedCells[r].r && p.c == attackedCells[r].c)
                    already_attackedp = true;
            }
        } while (already_attackedp == true);
        
        return p;
    }
    
    else
    { // ATTACK STATE
        
        // INITIAL BOOLEAN SETS THAT WILL CHANGE WITH DIFFERENT CONDITIONS (USED TO CHANGE INTO STATE)
        bool already_attackedp = false;
        bool cross_zone = false;
        
        do{
            already_attackedp = false;
            cross_zone = false;
            // random assignment
            p = game().randomPoint();
            for(int r = 0; r < attackedCells.size(); r++)
            { // already attacked
                
                if (p.r == attackedCells[r].r && p.c == attackedCells[r].c)
                    already_attackedp = true;
            }
            
            // SELECTING THE ZONE TO THE CROSS
            if(((abs(activated_point.r - p.r) <= 4) && activated_point.c == p.c) || ((abs(activated_point.c - p.c) <= 4) && activated_point.r == p.r))
            {
                cross_zone = true;
            }
            // IS IT IN THE ATTACK OR CROSS
        } while(already_attackedp ==  true || cross_zone == false);
        
        return p; // returns the point
    }

    return p; // returns the point
}

void MediocrePlayer::recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId)
{
    if(validShot == false)
        return; // should not be false, should return if it is


    // now that it is attacked, it should be added to the list
    attackedCells.push_back(p);


    // DORMANCY STATE CHANGES
    if(m_state == 1)
    {
        if(shotHit == 1)
            return; // remains dormant if missed shot
        else
        { // these have to do with HIT CONDITIONS

            if(shipDestroyed) // destroyed ship
                return;

            else
            { // OTHER HIT (NON DESTROYED)
                m_state = 2;
                activated_point = p;
                return;
            }
        }
    } // end dormancy initial state



    // STATE TWO THE ATTACK STATE :)
    if(m_state != 1)
    {
        int attacked_hitzone = 0;
        int cross_zoner = 0;


        for(int i = -4; i < 5; i++)
        { // ROWS OF THE CROSS
            Point a(activated_point.r + i, activated_point. c);

            if(game().isValid(a))
            {
                cross_zoner++;

            }

            for(int v=0; v< attackedCells.size(); v++)
            {
                if((attackedCells[v].r == activated_point.r + i) && (attackedCells[v].c == activated_point.c))
                    attacked_hitzone++;
                } // end forloop
        } // end the rows of the cross


        for(int i=-4; i<5; i++)
        {
            Point a(activated_point.r, activated_point.c+i);

            if(game().isValid(a) == true)
            {
                cross_zoner++;
            }

            for(int v = 0; v < attackedCells.size(); v++)
            {
                if((attackedCells[v].c == activated_point.c + i) && (attackedCells[v].r == activated_point.r))
                    attacked_hitzone++;
            }
        } // end loop for col



        // CROSS FINISHED SIGNIFYING THAT THE SHIP IS LARGER THAN 5
        if(attacked_hitzone == cross_zoner)
        {
            m_state = 1;
            return;
        }

        // MISSED IN THE CROSS
        if(shotHit == false)
            return; // dont do anything
        else
        {// SHIP DESTROYED?
            if(shipDestroyed == true)
            { // DONE WITH CROSS / SHIP
                m_state = 1;
                return;
            }
            else
            { // stay in attack mode
                return;
            }
        }

    }
}



void MediocrePlayer::recordAttackByOpponent(Point p){
    return;
}

//*********************************************************************
//  GoodPlayer
//*********************************************************************


class GoodPlayer : public Player {
public:
    GoodPlayer(string nm, const Game& g);
    ~GoodPlayer() {}
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
    
private:
        int m_state;
        bool recursive_placing(Board &b, int numShips);
        vector<Point> attackedCells;
        Point activated_point;
};

GoodPlayer::GoodPlayer(string nm, const Game& g) : Player(nm, g), m_state(1) {}



bool GoodPlayer::recursive_placing(Board &b, int numShips)
{ // will recursively place a ship using backtracking to keep starting similar to maze path backtracking
    
    // DATA STRUCTURE / LOCAL VARIABLE IMPLEMENTATIONS
    vector<Point> bad_locations; // used so that it doesnt reduntantly choose the same location

    // BASE CASE
    if(numShips == game().nShips())
        return true;
    
    // RECURSIVE STEP

    // Initial Loop through the Board to find a place to place the ships
    for(int i = 0; i < game().rows(); i++)
    { // first loop row
        for(int j = 0; j < game().cols(); j++)
        { // second loop col
            Point p(i, j);
            bool check_bad = false;
            
            for(int r = 0; r < bad_locations.size(); r++)
            {
                if(p.r == bad_locations[r].r && p.c == bad_locations[r].c)
                {
                    check_bad = true;
                }
            } // looping through the bad locations
            

            if(check_bad == false &&
               (b.placeShip(p, numShips, HORIZONTAL) ||
                b.placeShip(p, numShips, VERTICAL))) // test to place the ships down below
            { // successful placement of ship
                if(!recursive_placing(b, numShips + 1))
                {
                    if(b.unplaceShip(p, numShips, HORIZONTAL) == false)
                       {
                           b.unplaceShip(p, numShips, VERTICAL);
                       }
                    bad_locations.push_back(p);
                    i=0;
                    j=0;
                }
                else
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool GoodPlayer::placeShips(Board &b)
{ // returns true if placed, will place the things around 50 times.
    for(int i = 0; i < 50; i++)
    {
        // intial blocking of board
        b.block();
        
        if(recursive_placing(b, 0) == true)
        { // recursive call
            b.unblock(); // unblock if true since placed
            return true;
        }
        
        // unblocking board if failed for another attempt
        b.unblock();
    }
    return false;
}


Point GoodPlayer::recommendAttack()
{
    Point p;
    
    
    // INITIAL STATE THAT DECLARES DORMANCY
    
    if(m_state == 1)
    { // will choose a random point to attack since it is in state 1
        bool already_attackedp = false;
        do {
            already_attackedp = false;
            p = game().randomPoint();
            for(int r = 0; r < attackedCells.size(); r++)
            {
                if (p.r == attackedCells[r].r && p.c == attackedCells[r].c)
                    already_attackedp = true;
            }
        } while (already_attackedp == true);
        
        return p;
    }
    
    else
    { // ATTACK STATE
        
        // INITIAL BOOLEAN SETS THAT WILL CHANGE WITH DIFFERENT CONDITIONS (USED TO CHANGE INTO STATE)
        bool already_attackedp = false;
        bool cross_zone = false;
        
        do{
            already_attackedp = false;
            cross_zone = false;
            // random assignment
            p = game().randomPoint();
            for(int r = 0; r < attackedCells.size(); r++)
            { // already attacked
                
                if (p.r == attackedCells[r].r && p.c == attackedCells[r].c)
                    already_attackedp = true;
            }
            
            // SELECTING THE ZONE TO THE CROSS
            if(((abs(activated_point.r - p.r) <= 4) && activated_point.c == p.c) || ((abs(activated_point.c - p.c) <= 4) && activated_point.r == p.r))
            {
                cross_zone = true;
            }
            // IS IT IN THE ATTACK OR CROSS
        } while(already_attackedp ==  true || cross_zone == false);
        
        return p; // returns the point
    }

    return p; // returns the point
}


void GoodPlayer::recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId)
{
    if(validShot == false)
        return; // should not be false, should return if it is


    // now that it is attacked, it should be added to the list
    attackedCells.push_back(p);


    // DORMANCY STATE CHANGES
    if(m_state == 1)
    {
        if(shotHit == 1)
            return; // remains dormant if missed shot
        else
        { // these have to do with HIT CONDITIONS

            if(shipDestroyed) // destroyed ship
                return;

            else
            { // OTHER HIT (NON DESTROYED)
                m_state = 2;
                activated_point = p;
                return;
            }
        }
    } // end dormancy initial state



    // STATE TWO THE ATTACK STATE :)
    if(m_state != 1)
    {
        int attacked_hitzone = 0;
        int cross_zoner = 0;


        for(int i = -4; i < 5; i++)
        { // ROWS OF THE CROSS
            Point a(activated_point.r + i, activated_point. c);

            if(game().isValid(a))
            {
                cross_zoner++;

            }

            for(int v=0; v< attackedCells.size(); v++)
            {
                if((attackedCells[v].r == activated_point.r + i) && (attackedCells[v].c == activated_point.c))
                    attacked_hitzone++;
                } // end forloop
        } // end the rows of the cross


        for(int i=-4; i<5; i++)
        {
            Point a(activated_point.r, activated_point.c+i);

            if(game().isValid(a) == true)
            {
                cross_zoner++;
            }

            for(int v = 0; v < attackedCells.size(); v++)
            {
                if((attackedCells[v].c == activated_point.c + i) && (attackedCells[v].r == activated_point.r))
                {
                    attacked_hitzone++;
                }
            }
        } // end loop for col



        // CROSS FINISHED SIGNIFYING THAT THE SHIP IS LARGER THAN 5
        if(attacked_hitzone == cross_zoner)
        {
            m_state = 1;
            return;
        }

        // MISSED IN THE CROSS
        if(shotHit == false)
            return; // dont do anything
        else
        {// SHIP DESTROYED?
            if(shipDestroyed == true)
            { // DONE WITH CROSS / SHIP
                m_state = 1;
                return;
            }
            else
            { // stay in attack mode
                return;
            }
        }

    }
}


void GoodPlayer::recordAttackByOpponent(Point p){
    return;
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
