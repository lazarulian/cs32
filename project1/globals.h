//
//  globals.h
//  Project1
//
//  Created by Apurva Shah on 4/4/22.
//

#ifndef globals_h
#define globals_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;


// Global Variables for Game

const int MAXROWS = 20;             // max number of rows in the mesa
const int MAXCOLS = 25;             // max number of columns in the mesa
const int MAXGARKS = 150;           // max number of garks allowed
const int INITIAL_GARK_HEALTH = 2;

const int UP      = 0;
const int DOWN    = 1;
const int LEFT    = 2;
const int RIGHT   = 3;
const int NUMDIRS = 4;

// Global Utility Functions for Game

int randInt(int min, int max);
void clearScreen();



#endif /* globals_h */
