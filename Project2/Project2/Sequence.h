//
//  Sequence.h
//  Project2
//
//  Created by Apurva Shah on 4/15/22.
//

#ifndef Sequence_h
#define Sequence_h

///////////////////////////////////////////////////////////////////
// Declaration of the Type Alias
///////////////////////////////////////////////////////////////////
//using ItemType = std::string;
using ItemType = unsigned long;
// using ItemType = int;

///////////////////////////////////////////////////////////////////
// Sequence Class Declaration
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <string>

class Sequence
{
public:
    // Constructor, Destructor, Assignment Operator, Copy Constructor
    Sequence();
    ~Sequence();
    Sequence &operator=(const Sequence &src);
    Sequence(const Sequence &src);
    
    
    // Member Functions
    bool empty() const; // implemented
    int size() const; // implemented
    int insert(int pos, const ItemType& value); // implemented
    int insert(const ItemType& value); // implemented
    bool erase(int pos); // implemented
    int remove(const ItemType& value); // implemented
    bool get(int pos, ItemType& value) const; // implemented
    bool set(int pos, const ItemType& value); // implemented
    int find(const ItemType& value) const; // implemented
    void swap(Sequence& other);
    void dump() const; // implemented
    
private:
    struct Node
    {
        ItemType value;
        Node* next;
        Node* prev;
    };
    
    int m_size;
    Node* head;
    Node* tail;
    
};


#endif /* Sequence_h */
