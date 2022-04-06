//
//  Mesa.h
//  Project1
//
//  Created by Apurva Shah on 4/4/22.
//

#ifndef Mesa_h
#define Mesa_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

#include "globals.h"
#include "History.h"
using namespace std;

// Necessary for Compiler to Identify that it exists.
class Player;
class Gark;


class Mesa
{
  public:
        // Constructor/destructor
    Mesa(int nRows, int nCols);
    ~Mesa();

        // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     garkCount() const;
    int     numGarksAt(int r, int c) const;
    bool    determineNewPosition(int& r, int& c, int dir) const;
    void    display() const; // Want to model my display like this one

        // Mutators
    bool   addGark(int r, int c); // adds garks
    bool   addPlayer(int r, int c); // adds players
    bool   attackGarkAt(int r, int c, int dir); // attack of gark <- where I want the history function
    bool   moveGarks(); // Movement of Gark
    History& history();

  private:
    int     m_rows; // Rows in Game
    int     m_cols; // Columns in Game
    Player* m_player; // Player in Game
    Gark*   m_garks[MAXGARKS]; // Number of Garks in the Game
    int     m_nGarks; // Number of Garks
    History m_history;
};


#endif /* Mesa_h */

