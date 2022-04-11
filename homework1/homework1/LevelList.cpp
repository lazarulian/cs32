//
//  LevelList.cpp
//  homework1
//
//  Created by Apurva Shah on 4/10/22.
//

#include <stdio.h>
#include <iostream>
#include "Sequence.h"
#include "LevelList.h"

using namespace std;

LevelList::LevelList() : m_sequence()
{
}

bool LevelList::add(ItemType level)
{
    if (level >= MIN_LEVEL && level <= MAX_LEVEL && m_sequence.size() < DEFAULT_MAX_ITEMS)
    {
        m_sequence.insert(level);
        return true;
    }
    return false;
}

bool LevelList::remove(ItemType level)
{
    // Remove one instance of the specified level from the level list.
    // Return true if a level was removed; otherwise false.
    if(m_sequence.find(level) != -1)
    {
        m_sequence.erase(m_sequence.find(level));
        return true;
    }
    return false;
}

int LevelList::size() const
{
    // Return the number of levels in the list.
    return m_sequence.size();
}

ItemType LevelList::minimum() const
{
    // Return the lowest-valued level in the level list.  If the list is
    // empty, return NO_LEVEL.
    if(m_sequence.size() == 0)
    {
        return NO_LEVEL;
    }
    for (int i = 30; i < 401; i++)
    {
        if (m_sequence.find(i) != -1)
        {
            return i;
        }
    }
    return NO_LEVEL;
}

ItemType LevelList::maximum() const
{
    // Return the highest-valued level in the level list.  If the list is
    // empty, return NO_LEVEL.
    if(m_sequence.size() == 0)
    {
        return NO_LEVEL;
    }
    for (int i = 400; i > 29; i--)
    {
        if (m_sequence.find(i) != -1)
        {
            return i;
        }
    }
    return NO_LEVEL;
}
