//
//  Game.h
//  Project1
//
//  Created by Apurva Shah on 4/4/22.
//

#ifndef Game_h
#define Game_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

using namespace std;

class Mesa;

int decodeDirection(char dir);

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nGarks);
    ~Game();

        // Mutators
    void play();

  private:
    Mesa* m_mesa;
};


#endif /* Game_h */
