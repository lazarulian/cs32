// newSequence.h - Apurva Shah Homework 1


#ifndef newSequence_h
#define newSequence_h

#include <iostream>

// Declaration of the Type Alias
//using ItemType = std::string;
using ItemType = unsigned long;
// using ItemType = int;

// Global Variables
const int DEFAULT_MAX_ITEMS = 180;

// Declaration of the Sequence Class

class Sequence
{
public:
    Sequence();    // Create an empty sequence (i.e., one whose size() is 0).
    Sequence(int user_size);
    Sequence(const Sequence &src);
    Sequence& operator=(const Sequence &src);
    ~Sequence(); // Destructor for Sequence
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
    ItemType *m_arr;
    int dynamic_size;
    
};

#endif /* newSequence_h */
