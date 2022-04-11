//
//  LevelList.h
//  homework1
//
//  Created by Apurva Shah on 4/10/22.
//

#ifndef LevelList_h
#define LevelList_h

#include <iostream>
#include <limits>
#include "Sequence.h"

class Sequence;

const unsigned long NO_LEVEL = std::numeric_limits<unsigned long>::max();
    
const unsigned long MIN_LEVEL = 30;
const unsigned long MAX_LEVEL = 400;



class LevelList
{
public:
    LevelList();
    bool add(ItemType level);
    bool remove(ItemType level);
    int size() const;
    ItemType minimum() const;
    ItemType maximum() const;
    
private:
    Sequence m_sequence;
    
};




#endif /* LevelList_h */
