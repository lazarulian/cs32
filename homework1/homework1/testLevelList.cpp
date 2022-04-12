//
//  testLevelList.cpp
//  homework1
//
//  Created by Apurva Shah on 4/10/22.


#include <stdio.h>
#include <iostream>
#include <cassert>
#include "Sequence.h"
#include "LevelList.h"

int main() {
    
    
    LevelList l;
    assert(l.size() == 0);
    assert(l.add(31) == true);
    assert(l.size() == 1);
    assert(l.add(460) == false);
    assert(l.add(53) == true);
    assert(l.add(22) == false);
    assert(l.add(46) == true);
    assert(l.add(22) == false);
    assert(l.add(88) == true);
    assert(l.size() == 4);
    assert(l.remove(46) == true);
    assert(l.size() == 3);
    assert(l.remove(34) == false);
    assert(l.maximum() == 88);
    assert(l.minimum() == 31);
    
    return 0;
}
