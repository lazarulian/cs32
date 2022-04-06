//
//  Player.h
//  Project1
//
//  Created by Apurva Shah on 4/4/22.
//

#ifndef Player_h
#define Player_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

class Mesa;

using namespace std;

class Player
{
  public:
        // Constructor
    Player(Mesa *mp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;

        // Mutators
    void   stand();
    void   moveOrAttack(int dir);
    void   setDead();

  private:
    Mesa* m_mesa;
    int   m_row;
    int   m_col;
    int   m_age;
    bool  m_dead;
};

#endif /* Player_h */
