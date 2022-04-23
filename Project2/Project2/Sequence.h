// Sequence.h
// Apurva Shah 705595011

#include <stdio.h>
#include <iostream>
#include <string>

#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

using ItemType = std::string;

////////////////////////////////
///  Class Declaration
////////////////////////////////

class Sequence
{
    public:
    // Constructor, Destructor, Assignment Operator, Copy Constructor
    Sequence();
    ~Sequence();
    Sequence(const Sequence &src);
    Sequence &operator=(const Sequence &src);

    // Public Member Functions
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType &value);
    int insert(const ItemType &value);
    bool erase(int pos);
    int remove(const ItemType &value);
    bool get(int pos, ItemType &value) const;
    bool set(int pos, const ItemType &value);
    int find(const ItemType &value) const;
    void swap(Sequence &other);

    private:
    int m_size;

    // Declaring the Nodes
    struct Node
    {
        ItemType value;
        Node *next;
        Node *prev;
    };

    Node *head;
    Node *tail;
    // based off of nachenberg slides
    void add_to_sequence(int pos, const ItemType &value);
    void addFront(const ItemType &value);
    void addRear(const ItemType &value);
    bool delete_element(int pos);
};

////////////////////////////////
/// Algorithms
////////////////////////////////
int subsequence(const Sequence &seq1, const Sequence &seq2);
void interleave(const Sequence &seq1, const Sequence &seq2, Sequence &result);

#endif // SEQUENCE_INCLUDED
