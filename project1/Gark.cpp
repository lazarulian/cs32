//
//  Gark.cpp
//  Project1
//
//  Created by Apurva Shah on 4/4/22.
//

#include <stdio.h>
#include "Gark.h"
#include "globals.h" // Necessary for the implementation of Mesa classes
#include "Mesa.h" // Necessary for the implementation of Mesa classes

///////////////////////////////////////////////////////////////////////////
//  Gark implementation
///////////////////////////////////////////////////////////////////////////

Gark::Gark(Mesa* mp, int r, int c)
 : m_mesa(mp), m_row(r), m_col(c), m_health(INITIAL_GARK_HEALTH)
{
    if (mp == nullptr)
    {
        cout << "***** A gark must be created in some Mesa!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > mp->rows()  ||  c < 1  ||  c > mp->cols())
    {
        cout << "***** Gark created with invalid coordinates (" << r << ","
             << c << ")!" << endl;
        exit(1);
    }
}

int Gark::row() const
{
    return m_row;
}

int Gark::col() const
{
    return m_col;
}

void Gark::move()
{
      // Attempt to move in a random direction; if it can't move, don't move
    int dir = randInt(0, NUMDIRS-1);  // dir is now UP, DOWN, LEFT, or RIGHT
    m_mesa->determineNewPosition(m_row, m_col, dir);
}

bool Gark::getAttacked(int dir)  // return true if dies
{
    m_health--;
    if (m_health == 0)
        return true;
    if ( ! m_mesa->determineNewPosition(m_row, m_col, dir))
    {
        m_health = 0;
        return true;
    }
    return false;
}
