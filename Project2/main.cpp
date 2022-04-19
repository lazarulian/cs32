//
//  main.cpp
//  Project2
//
//  Created by Apurva Shah on 4/15/22.
//

#include <iostream>
#include <cassert>
#include <string>

#include "Sequence.h"

using namespace std;


int main() {
    Sequence s;
    s.insert(0, 16);
    s.insert(15);
    s.insert(0, 32);
    s.dump();
    s.find(200);
    cout << "2" << endl;
    return 0;
}
