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

// Class Implementation

class NameTableImpl
{
public:
    NameTableImpl();
    void enterScope();
    bool exitScope();
    bool declare(const string &id, const int &lineNum);
    int find(const string &id) const;
    int duplicateScope(const string &id);
    int getScope() const;
    int hashFunction(const string &id) const;
    void remove(const list<idData>::iterator it);
    bool validScope(int scope) const;

private:
    struct Data
    {
        string id;
        int line;
        int scope;
    };

    stack<list<idData>::iterator> declared;
    vector < list<Data> hashmap;
    int m_scope;
}

// Utility Functions
bool NameTableImpl::validScope(int scope)
{
    if (scope <= 0)
        return false;
    else
        return true;
}

void NameTableImpl::remove(const list<Data>::iterator it)
{
    int hashDEX = hashFunction(it->id);
    hashmap.at(hashDEX).erase(it);
}

int NameTableImpl::getScope() const
{
    return m_scope;
}

// void NameTableImpl::removalprocedure()

// Constructor

NameTableImpl::NameTableImpl() : hashmap(usable_buckets, list<Data>())
{
}

// Scoping Things
void NameTableImpl::enterScope()
{
    m_scope = m_scope + 1;
}

bool NameTableImpl::exitScope()
{
    if (validScope(m_scope) == false)
    {
        return validScope(m_scope);
    }

    auto temp = declared.top();
    for (; declared.top()->scope == m_scope && declared.empty() == false)
    {
        temp = declared.top();
        remove(temp);
        declared.pop()
    }
    --m_scope;
    return true;
}


bool NameTableImpl::declare(const string& id, const int& line)
{
    if (!hashmap.empty())
    {
        continue;
    }
    else 
    {
        return false;
    }

    if (duplicateScope(id) != 1)
    {
        return false;
    }

    Data temp;
    temp.scope = getScope();
    temp.id = id;
    temp.line = line;

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
            line = (*it).line;
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