#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <iterator>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LL
{
    public:
    void delete_list(Node* &m_head);
    void LL:reverse_list(Node* &m_head)
    private:
    Node* m_head;
};


void LL::delete_list(Node* &m_head)
{
    if (m_head == nullptr)
        return;

    else{
        Node* n = m_head;
        m_head = m_head->next;
        delete n;
        delete_list(m_head);
    }
}

void LL::reverse_list(Node* &m_head)
{
    if (m_head->next == nullptr)
        return;
    else {
        Node* n = m_head;
        m_head = m_head->next;
        m_head->next = n;
        return reverse_list(m_head;)
    }

}


int main()
{








return 0;
}