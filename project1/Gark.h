//  Gark.h
//  Project1
//
//  Created by Apurva Shah on 4/4/22.
//

#ifndef Gark_h
#define Gark_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

using namespace std;


class Mesa;  // This is needed to let the compiler know that Mesa is a
             // type name, since it's mentioned in the Gark declaration.

class Gark
{
  public:
        // Constructor
    Gark(Mesa* mp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;

        // Mutators
    void move();
    bool getAttacked(int dir);

  private:
    Mesa* m_mesa;
    int   m_row;
    int   m_col;
    int   m_health;
};

#endif /* Gark_h */
