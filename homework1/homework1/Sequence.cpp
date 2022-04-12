//
//  Sequence.cpp
//  homework1
//
//  Created by Apurva Shah on 4/9/22.
//

#include <stdio.h>
#include <iostream>
#include "Sequence.h"
using namespace std;

Sequence::Sequence() : m_size(0), m_cap(0)
{ // Create an empty sequence (i.e., one whose size() is 0)
    
} // End Default Constructor

bool Sequence::empty() const
{ // Return true if the sequence is empty, otherwise false.
    if (m_size == 0)
    {
        return true;
    }
    
    return false;
} // End Bool Sequence


int Sequence::size() const
{
    // Return the number of items in the sequence.
    return m_size;
}

int Sequence::insert(int pos, const ItemType& value)
{
    
    // Case if Array is already at capacity
    if (m_size >= DEFAULT_MAX_ITEMS || pos > m_size || pos < 0) {
        cerr << "you fucked up somewhere in the insert" << endl;
        return -1;
    }
    
    if (pos < m_size) {
        for (int i = pos; i < m_size; i++) {
            m_arr[i+1] = m_arr[i];
        }
        m_arr[pos] = value;
        m_size++;
        cerr << "Inserted through shift right" << endl;
        return 0;
    }
    
    if (pos == m_size) {
        m_arr[m_size] = value;
        m_size++;
        cerr << "inserted through regular" << endl;
        return 0;
    }
    
    return 0;
} // End Insert


int Sequence::insert(const ItemType& value)
{
    // Sequence is Empty
    if (m_size == 0)
    {
        cerr << "Inserted at position 0" << endl;
        m_arr[0] = value;
        m_size++;
        return 0;
    }
    
    // Sequence is Full
    if (m_size == DEFAULT_MAX_ITEMS)
    {
        cerr << "Could not insert because reached max elements" << endl;
        return -1;
    }
    
    // Finding the Smallest Value
    ItemType p = m_arr[0];
    int p_pos = 0;
    for (int i = 0; i < m_size; i++)
    {
        if (m_arr[i] < p)
        {
            p = m_arr[i];
            p_pos = i;
        }
        else
        {
            continue;
        } // end else
    } // end loop
    
    // Checking if value is greater than all of the elements in the sequence
    
    if (value > p)
    {
        m_arr[m_size] = value;
        m_size++;
        return m_size;
    }
    
    
    // Adding and Shifting Based off of smallest p
    
    for (int i = p_pos; i < m_size; i++) {
        for (int j = p_pos+1; j < m_size+1; j++) {
            m_arr[j] = m_arr[i];
        }
    }
    // Inserting P
    m_arr[p_pos] = value;
    m_size++;
    return p_pos;
    
    return 0;
}


bool Sequence::erase(int pos)
{
    if (0 <= pos && pos < m_size) {
        for (int i = pos; i < m_size; i++) {
            for (int j = pos+1; j < m_size; j++) {
                m_arr[i] = m_arr[j];
            }
        } // end loop
        m_size--;
        return true;
    }
    return false;
}

int Sequence::remove(const ItemType& value)
{
    int removal_counter = 0;
    for (int i = 0; i < m_size; i++) {
        if (m_arr[i] == value) {
            m_size--;
            cerr << i << endl;
            for (int j = i; j < m_size; j++) {
                m_arr[j] = m_arr[j+1];
            }
            removal_counter++;
        } // end if
    }
    return removal_counter;
}


bool Sequence::get(int pos, ItemType& value) 
{
    if (0 <= pos && pos < m_size) {
        value = m_arr[pos];
        cerr << "The value that has been returned is " << m_arr[pos] << endl;
        return true;
    }
    return false;
} // Bool Get



bool Sequence::set(int pos, const ItemType& value)
{
    if (0 <= pos && pos < m_size) {
        m_arr[pos] = value;
        return true;
    }
    return false;
}

int Sequence::find(const ItemType& value) const
{
    for (int i = 0; i < m_size; i++) {
        if (m_arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void Sequence::swap(Sequence& other)
{
    int temp_size = other.m_size;
    other.m_size = this-> m_size;
    this->m_size = temp_size;
    
    ItemType holder;
    
    for (int i = 0; i <= DEFAULT_MAX_ITEMS; i++) {
        holder = other.m_arr[i];
        other.m_arr[i] = this->m_arr[i];
        this->m_arr[i] = holder;
    }
    
}
