//
//  Sequence.cpp
//  Project2
//
//  Created by Apurva Shah on 4/15/22.
//

#include <stdio.h>
#include <iostream>
#include <cassert>
#include <string>

#include "Sequence.h"

using namespace std;

Sequence::Sequence() : head(nullptr), tail(nullptr), m_size(0)
{ // creates empty linked list
}

Sequence::~Sequence()
{ // destructor
    if (head == nullptr)
    { // sequence is not empty
        delete head;
        delete tail;
    }
    else
    { // sequence is not empty
        Node* p;
        p = head;
        
        while(p->next != nullptr) {
            Node* n;
            n = p;
            p = p->next;
            delete n;
        }
        delete p;
    }
}

//Sequence& Sequence::operator=(const Sequence &src)
//{ // assignment constructor
//
//
//}

Sequence::Sequence(const Sequence &src)
{ // copy constructor
    
}


// Member Functions

bool Sequence::empty() const
{ // checks if function is empty
    if (head == nullptr && m_size == 0) {
        cerr << "The sequence is empty" << endl;
        return true;
    }
    cerr << "The sequence is not empty" << endl;
    return false;
}

int Sequence::size() const
{ // returns the size of the sequence
    cerr << "The size of the sequence is: " << m_size << endl;
    return m_size;
}

int Sequence::insert(int pos, const ItemType& value)
{
    
    if (pos<0 || m_size < pos) {
        cerr << "Item could not be inserted because position is out of range: " << "-1" << endl;
        return -1;
    }
    Node* p;
    if (head == nullptr)
    { // empty list
        p = new Node;
        p->value = value;
        p->next = nullptr;
        p->prev = nullptr;
        head = p;
        tail = p;
        cerr << "Inserted as the first value of the linked list" << endl;
        m_size++;
        return 0;
    }
    
    // Inserting at the Head
    if (pos == 0 && head != nullptr)
    { // empty list
        p = head;
        Node* n;
        n = new Node;
        n->value = value;
        n->next = p;
        n->prev = nullptr;
        p->prev = n;
        head = n;
        cerr << "Inserted as the first value of the linked list" << endl;
        m_size++;
        return 0;
    }
    
    // Inserting at the Tail
    
    if (pos == m_size)
    {
        p = tail;
        Node* n;
        n = new Node;
        n->value = value;
        n->next = nullptr;
        n->prev = p;
        p->next = n;
        tail = n;
        m_size++;
        cerr << "Inserted at the tail!" << endl;
        return 0;
    }
    
    // Inserting Regularly
    int pos_counter = 0;
    p = head;
    
    while (p != nullptr) {
        if (pos_counter == pos) {
            Node* n = new Node;
            n->value = value;
            n->prev = p->prev;
            n->next = p;
            p->prev->next = n;
            p->prev = n;
            break;
        }
        if (p->next == nullptr) {
            break;
        }
        p = p->next;
        pos_counter++;
    }
    m_size++;
    cerr << "Inserted Correctly baby" << endl;
    return(0);
}

int Sequence::insert(const ItemType& value)
{ // Inserts at first instance of value smaller than number in linked list
    // Parsing through List to see if possible
    int pos_index = 0;
    Node* p = head;
    
    if (head == nullptr)
    { // empty list
        Node* n = new Node;
        n->value = value;
        n->next = nullptr;
        n->prev = nullptr;
        head = n;
        tail = n;
        cerr << "Inserted into an empty list" << endl;
        m_size++;
        return 0;
    }
    
    while (p->next != nullptr) {
        if (value <= p->value) {
            break;
        }
        p = p->next;
        pos_index++;
    }
    if (pos_index == m_size-1 && value > p->value) {
        this->insert(m_size, value);
        return m_size-1;
    }
    this->insert(pos_index, value);
    return pos_index;
}

bool Sequence::erase(int pos)
{ // erase a value and remove it
    
    // checking for incorrect pos
    if (pos > m_size-1) {
        return false;
    }
    Node* p = head;
    
    // removing with one
    if (p->next == nullptr && m_size == 1) {
        head = nullptr;
        tail = nullptr;
        delete p;
        m_size--;
        return true;
    }
    
    int pos_counter = 0;
    while (p->next != nullptr) {
        if (pos_counter == pos) {
            break;
        }
        p = p->next;
        pos_counter++;
    }
    // head removal
    if (p->prev == nullptr) {
        p->next->prev = nullptr;
        head = p->next;
        delete p;
        cerr << "hit 2" << endl;
        m_size--;
        return true;
    }
    // tail element removal
    if (p->next == nullptr)
    {
        p->prev->next = nullptr;
        tail = p->prev;
        delete p;
        m_size--;
        cerr << "hit 3" << endl;
        return true;
    }
    
    p->next->prev = p->prev;
    p->prev->next = p->next;
    cerr << "hit 4" << endl;
    delete p;
    m_size--;
    return true;
}

int Sequence::remove(const ItemType& value) {
    int items_removed = 0;
    Node* p;
    p = head;
    for (int i = 0; i < m_size; i++) {  //find index of value to delete
        if (p->value == value) {
            erase(i);
            i--;
            items_removed++;
        }
        p = p->next;
    }
    if (items_removed == 0) {
        cerr << "ddint remove shit" << endl;
    }
    return items_removed;
}

bool Sequence::get(int pos, ItemType& value) const
{    // copies pos into value
    
    if (pos > m_size-1) {
        cerr << "Inputted the wrong position" << endl;
        return false;
    }
    
    Node* p = head;
    int pos_counter = 0;
    while (p->next != nullptr) {
        if (pos_counter == pos) {
            break;
        }
            p = p->next;
            pos_counter++;
    } // end while
        if (p!= nullptr)
        {
            value = p->value;
            return true;
        }
        else{
            return false;
        }
}

bool Sequence::set(int pos, const ItemType& value) {
    if (0 <= pos < m_size) {
        Node* p = head;
        int pos_counter = 0;
        while (p->next != nullptr) {
            if (pos_counter == pos) {
                break;
            }
                p = p->next;
                pos_counter++;
        } // end while
            if (p!= nullptr)
            {
                p->value = value;
                return true;
            }
    }
    return false;
}

int Sequence::find(const ItemType& value) const
{ // find pos of value
    int pos_counter = 0;
    if (m_size == 0) {
        return -1;
    }
    Node* p = head;
    while (p->next != nullptr) {
        if (p->value == value) {
            break;
        }
        p = p->next;
        pos_counter++;
    }
    if (pos_counter == m_size-1) {
        return -1;
    }
    cerr << "Found at this position: " << pos_counter << endl;
    return pos_counter;
}

//void Sequence::swap(Sequence& other);


void Sequence::dump() const {
    // Print out the value of each entry
    for (Node* p = head; p != nullptr; p = p->next) {
        cerr << p->value << " ";
        
    }
    cerr << endl;
}
