// Apurva Shah 705595011

// This is a correct but inefficient implementation of
// the NameTable functionality.

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <functional>

// Header Declarations
#include "nameTable.h"

using namespace std;

// Global Variables
const int total_buckets = 20000;
const int usable_buckets = 19997;

class NameTableImpl
{
public:
    // constructor
    NameTableImpl() : m_scope(0), hashmap(usable_buckets, list<Data>())
    {;}
    
    // member functions
    void enterScope();
    bool exitScope();
    bool declare(const string& id, const int& lineNum);
    int find(const string& id) const;
    int duplicateScope(const string& id);
    int hashFunction(const string& id) const;
    int getScope() const;
    bool validScope(int scope) const;

    
private:
    struct Data
    {
        string id;
        int scope;
        int lineNum;
        Data(string m_id, int m_scope, int m_num) : id(m_id), scope(m_scope), lineNum(m_num) {}
    };
    
    stack<list<Data>::iterator> declared;
    void remove(const list<Data>::iterator it);
    vector<list<Data>> hashmap;
    int m_scope;
};

// Utility Functions
bool NameTableImpl::validScope(int scope) const
{
   if (scope <= 0)
       return false;
   else
       return true;
}

int NameTableImpl::getScope() const
{
   return m_scope;
}

void NameTableImpl::remove(const list<Data>::iterator it)
{
   int hashDEX = hashFunction(it->id);
   hashmap.at(hashDEX).erase(it);
}

// Regular Functions

int NameTableImpl::hashFunction(const string &id) const
{
   return hash<string>()(id) % usable_buckets;
}


void NameTableImpl::enterScope() {
    ++m_scope;
}


bool NameTableImpl::exitScope()
{
    if (validScope(m_scope) == false)
    {
        return validScope(m_scope);
    }

    auto temp = declared.top();
    for (; declared.top()->scope == m_scope && declared.empty() == false;)
    {
        temp = declared.top();
        remove(temp);
        declared.pop();
    }
    --m_scope;
    return true;
}


bool NameTableImpl::declare(const string& id, const int& line)
{
    if (!hashmap.empty())
    {
//        cerr << "wasnt empty" << endl;
    }
    else
    {
        return false;
    }

    if (duplicateScope(id) != 0)
    {
        return false;
    }

    Data temp(id, getScope(), line);
    
    int hashspot = hashFunction(id);
    list<Data> &bucket = hashmap.at(hashspot);
    bucket.push_back(temp);
    declared.push(--bucket.end());
    return true;
}

int NameTableImpl::duplicateScope(const string &id)
{
    int hashspot = hashFunction(id);
    list<Data> &bucket = hashmap.at(hashspot);
    auto it = bucket.begin();
    while (it != bucket.end())
    {
        if ((*it).id == id && (*it).scope == m_scope)
        {
            return 1;
        }
        it++;
    }
    return 0;
}


int NameTableImpl::find(const string& id) const
{
    int found = 0;
    int line;
    int largestScope = 0;
    int hashspot = hashFunction(id);
    const list<Data> &bucket = hashmap.at(hashspot);
    auto it = bucket.begin();
    while (it != bucket.end())
    {
        if ((*it).id == id && (*it).scope >= largestScope)
        {
            line = (*it).lineNum;
            found = 1;
            largestScope = (*it).scope;
        }
        it++;
    }
    if (found == 0)
        return -1;
    else
        return line;
}


//*********** NameTable functions **************

// For the most part, these functions simply delegate to NameTableImpl's
// functions.

NameTable::NameTable()
{
    m_impl = new NameTableImpl;
}

NameTable::~NameTable()
{
    delete m_impl;
}

void NameTable::enterScope()
{
    m_impl->enterScope();
}

bool NameTable::exitScope()
{
    return m_impl->exitScope();
}

bool NameTable::declare(const string& id, int lineNum)
{
    return m_impl->declare(id, lineNum);
}

int NameTable::find(const string& id) const
{
    return m_impl->find(id);
}
