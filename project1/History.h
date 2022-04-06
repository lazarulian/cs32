//
//  History.h
//  Project1
//
//  Created by Apurva Shah on 4/4/22.
//

#ifndef History_h
#define History_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

#include "globals.h"

using namespace std;

class History {
    public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;

        void access(int r, int j) const;
            
    private:
        int mRows;
        int mCols;
        int mGrid[MAXROWS][MAXCOLS];
};


#endif /* History_h */
