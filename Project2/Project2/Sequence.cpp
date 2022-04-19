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

// Constructor
Sequence::Sequence() : head(nullptr), tail(nullptr), m_size(0)
{ // creates empty linked list
}

// Copy Constructor

Sequence::Sequence(const Sequence &src)
{
    // set data members
    m_size = src.m_size;
    
    // empty sequence
    if (src.m_size == 0) {
        head = nullptr;
        tail = nullptr;
    }
    
    // Copying Sequence from nonempty sdequence
    else {
        // initialize head
        head = new Node;
        head->prev = nullptr;
        Node* p = head;
        
        // initialize middle nodes
        for (Node* n = src.head; n->next != nullptr; n = n->next) {
            Node* z = new Node;
            p->value = n->value;
            p->next = z;
            z->prev = p;
            p = z;
        }
        
        // initialize tail
        p->value = src.tail->value;
        p->next = nullptr;
        tail = p;
    }
    
}

Sequence& Sequence::operator=(const Sequence &src)
{
    // Checking if this is the same
    if(&src == this) {
        return *this;
    }
    
    Node* p = head;
    Node* a;
    
    while (p!= nullptr)
    {
        a = p;
        p = p->next;
        delete a;
    }
    
    this->m_size = src.m_size;
    
    if (src.m_size == 0) {
        this->head = nullptr;
        this->tail = nullptr;
        return *this;
    }
    
    // For Sequences Larger than 1
    
    // Creating the head
    Node* o; // traverses inputted linked list
    Node* t; // traverses new linked list
    
    p = new Node;
    p->value = src.head->value;
    p->prev = nullptr;
    p->next = nullptr;
    head = p;
    
    t = this->head;
    
    for (o = src.head->next; o != nullptr; o = o->next)
    {
        Node* n = new Node;
        n->value = o->value;
        n->prev = t;
        n->next = nullptr;
        t->next = n;
        t = n;
    }
    return *this;
}


// Destructor
Sequence::~Sequence()
{ // destructor
    if (head == nullptr)
    { // sequence is empty
        return;
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
    }
}

////////////////////////////////////////////
// Member Functions
////////////////////////////////////////////

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
    if (pos == 0)
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
        return pos;
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
        return pos;
    }
    
    // Inserting Regularly
    p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
    }
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = p->next;
    newNode->prev = p;
    p->next = newNode;
    newNode->next->prev = newNode;
    m_size++;
    return(pos);
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
    
    if (pos > m_size-1 || pos < 0) {
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
    if (0 <= pos && pos < m_size) {
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
    while (p!= nullptr) {
        if (p->value == value) {
            break;
        }
        p = p->next;
        pos_counter++;
    }
    if (p!= nullptr) {
        cerr << "Found at this position: " << pos_counter << endl;
        return pos_counter;
    }
    else {
        return -1;
    }
}

void Sequence::swap(Sequence& other)
{ // Swaps the Sequences
    
    // initial data member copying
    int temp_size = this->m_size;
    this->m_size = other.m_size;
    other.m_size = temp_size;
    
    // swapping the linked lists by altering where the head points to (access point)
    Node* temp_head = this->head;
    this->head = other.head;
    other.head = temp_head;
}


void Sequence::dump() const {
    // Print out the value of each entry
    for (Node* p = head; p != nullptr; p = p->next) {
        cerr << p->value << " ";
        
    }
    cerr << endl;
}

////////////////////////////////////////////
// Algorithms
////////////////////////////////////////////


int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    if (seq1.size() == 0 || seq2.size() == 0)
    {
        return -1;
    }
    // Declaring array of values in linked list
    ItemType* m_arr;
    m_arr = new ItemType[seq2.size()];
    for (int i = 0; i < seq2.size(); i++)
    {
        seq2.get(i, m_arr[i]);
    }
    
    
    for (int i = 0; i < seq1.size(); i++)
    {
        ItemType temp;
        int victory_counter = 0;
        seq1.get(i, temp);
        if (temp == m_arr[0]) {
            int start_pos = i;
            for (int j = 0; j<seq2.size(); j++)
            {
                seq1.get((i+j), temp);
                if (temp == m_arr[j]) {
                    victory_counter++;
                    continue;
                }
                else {
                    start_pos = -1;
                    victory_counter = 0;
                    break;
                }
            } // end subforloop
            if (victory_counter == seq2.size()) {
                return start_pos;
            }
        } // end if
        
    }
    
    delete [] m_arr;
    return -1;
}

// Interleave

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result) {
    
    //check if any of the sequences are empty
    if (seq1.empty() == true && seq2.empty() != true) {
        result = seq2;
    }
    else if (seq2.empty() == true && seq1.empty() != true) {
        result = seq1;
    }
    else if (seq1.empty() == true && seq2.empty() == true) {    //if both sequences are empty, result should be empty
        for (int i = (result.size() - 1); i >= 0; i--) {       //clear result so we can put stuff in it
            result.erase(i);
        }
    }
    
    //both sequences have stuff in them
    else {
        Sequence temp;                      //in case of aliasing
        
        if (result.empty() == false) {
            temp = result;
        }
        
        for (int i = (temp.size() - 1); i >= 0; i--) {       //clear result so we can put stuff in it
            temp.erase(i);
        }
        
        int difference = 0;
        difference = seq1.size() - seq2.size();
        if (difference < 0) {
            difference = difference * -1;
        }
        
        int iterations = 0;                 //figure out how many times to iterate the for loop, depending on size of                                       sequences
        if (seq1.size() == seq2.size()) {
            iterations = seq1.size() + seq2.size(); //iterate enough times to put all items of each in the seq
        }
        else {
            iterations = seq1.size() + seq2.size() + (difference * 2);
            //add items in both sequences
            //difference in items between sequences multiplied by 2 b/c the for loop depends on whether i is even or odd
            //without multiplying difference by 2, this code will not update result if i is even or odd
            //both if statements below will never be satisfied: either i is not even/odd, or the sequence counter is not less than the size
        }
        
        ItemType seq1val;
        ItemType seq2val;
        
        int seq1counter = 0;            //keeps track of the number of elements in seq1
        int seq2counter = 0;            //keeps track of the number of elements in seq2
        int generalCounter = 0;         //keeps track of the number of elements in result
        
        for (int i = 0; i < iterations; i++) {
            if (i % 2 == 0 || i == 0) {             //if i is even, input a member from seq1
                if (seq1counter < seq1.size()) {    //AND if there are still items left in seq 1
                    seq1.get(seq1counter, seq1val);
                    temp.insert(generalCounter, seq1val);
                    seq1counter++;
                    generalCounter++;
                }
            }
            
            else if (i % 2 == 1) {                  //if i is odd, input a member from seq 2
                if (seq2counter < seq2.size()) {    //AND if there are still items left in seq 2
                    seq2.get(seq2counter, seq2val);
                    temp.insert(generalCounter, seq2val);
                    seq2counter++;
                    generalCounter++;
                }
            }
        }
        result = temp;
    }
    
}
