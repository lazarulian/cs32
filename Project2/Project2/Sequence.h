//
//  Sequence.h
//  Project2
//
//  Created by Apurva Shah on 4/15/22.
//

#ifndef Sequence_h
#define Sequence_h

#include <iostream>
#include <cassert>
#include <string>

///////////////////////////////////////////////////////////////////
// Declaration of the Type Alias
///////////////////////////////////////////////////////////////////
//using ItemType = std::string;
//using ItemType = unsigned long;
 using ItemType = int;

///////////////////////////////////////////////////////////////////
// Sequence Class Declaration
///////////////////////////////////////////////////////////////////


class Sequence
{
public:
    // Constructor, Destructor, Assignment Operator, Copy Constructor
    Sequence(); // implemented
    ~Sequence(); // implemented
    Sequence &operator=(const Sequence &src); // implemented
    Sequence(const Sequence &src); // implemented
    
    
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
    void swap(Sequence& other); // implemented
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

///////////////////////////////////////////////////////////////////
// Non Member Functions
///////////////////////////////////////////////////////////////////

int subsequence(const Sequence& seq1, const Sequence& seq2); // implemented
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);


#endif /* Sequence_h */
