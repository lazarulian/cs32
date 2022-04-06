//
//  History.cpp
//  Project1
//
//  Created by Apurva Shah on 4/4/22.
//

#include <stdio.h>
#include "History.h"

// Constructor Implementation

History::History(int nRows, int nCols) : mRows(nRows), mCols(nCols)
{

    // Creating the Integer Grid
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            mGrid[i][j] = 0;
        }
    }
}

// Mutator
bool History::record(int r, int c) {
    // Will change default grid values (0) to numerical representations of amount of garks attacked in this position
    if (r <= 0 || c <= 0 || r > mRows || c > mCols) {
        return false;
    }
    mGrid[r-1][c-1]++;
    return true;
}

// Accessor

void History::display() const
{
    clearScreen();
// Takes the numerical grid and converts each of the numerical representation of gark attacks to what should be displayed in
// character values in the same grid formation
    
    for (int i = 0; i < mRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            char ch = '.'; // default grid uses dots
            int n = mGrid[i][j];
            if (n >= 26)
                ch = 'Z';
            else if (n > 0)
                ch = 'A' + n-1; // increments lettering based off of attack
            cout << ch;
        } // end col for loop
        cout << endl;
    } // end row for loop
    cout << endl;
}
