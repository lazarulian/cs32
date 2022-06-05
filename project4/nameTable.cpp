// NameTable.cpp

// This is a correct but inefficient implementation of
// the NameTable functionality.

#include "nameTable.h"
#include <string>
#include <list>
#include <vector>
using namespace std;

  // This class does the real work of the implementation.

class NameTableImpl
{
  public:
    void enterScope();
    bool exitScope();
    bool declare(const string& id, int lineNum);
    int find(const string& id) const;
  private:
    // Declaring the Structure of the Node
    struct Node
    {
        int scopeID;
        int stringID;
        int line_number;
    };
    // Declaring the DS for the Hash Function
    vector<list<Node>*> buckets;
    vector<string> m_ids;
    vector<int> m_lines;
};

void NameTableImpl::enterScope()
{
      // Extend the id vector with an empty string that
      // serves as a scope entry marker.

    m_ids.push_back("");
    m_lines.push_back(0);
}

bool NameTableImpl::exitScope()
{
      // Remove ids back to the last scope entry.

    while (!m_ids.empty()  &&  m_ids.back() != "")
    {
        m_ids.pop_back();
        m_lines.pop_back();
    }
    if (m_ids.empty())
        return false;

      // Remove the scope entry marker itself.

    m_ids.pop_back();
    m_lines.pop_back();
    return true;
}

bool NameTableImpl::declare(const string& id, int lineNum)
{
    if (id.empty())
        return false;

      // Check for another declaration in the same scope.
      // Return if found, break out if encounter the scope
      // entry marker.

    size_t k = m_ids.size();
    while (k > 0)
    {
        k--;
        if (m_ids[k].empty())
            break;
        if (m_ids[k] == id)
            return false;
    }

      // Save the declaration

    m_ids.push_back(id);
    m_lines.push_back(lineNum);
    return true;
}

int NameTableImpl::find(const string& id) const
{
    if (id.empty())
        return -1;

      // Search back for the most recent declaration still
      // available.

    size_t k = m_ids.size();
    while (k > 0)
    {
        k--;
        if (m_ids[k] == id)
            return m_lines[k];
    }
    return -1;
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
