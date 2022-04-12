//
//  Sequence.h
//  homework1
//
//  Created by Apurva Shah on 4/9/22.
//

#ifndef Sequence_h
#define Sequence_h
#include <iostream>

///////////////////////////////////////////////////////////////////
// Declaration of the Type Alias
///////////////////////////////////////////////////////////////////
//using ItemType = std::string;
using ItemType = unsigned long;
// using ItemType = int;

///////////////////////////////////////////////////////////////////
// Global Variables
///////////////////////////////////////////////////////////////////
const int DEFAULT_MAX_ITEMS = 180;

///////////////////////////////////////////////////////////////////
// Sequence Class Declaration
///////////////////////////////////////////////////////////////////

class Sequence
{
public:
    Sequence();    // Create an empty sequence (i.e., one whose size() is 0).
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.
    
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    
    bool erase(int pos);
    
    int remove(const ItemType& value);
    
    bool get(int pos, ItemType& value);
    
    bool set(int pos, const ItemType& value);
    
    int find(const ItemType& value) const;
    
    void swap(Sequence& other);
    
private:
    int m_size;
    int m_cap;
    ItemType m_arr[DEFAULT_MAX_ITEMS];
    
};


#endif /* Sequence_h */
