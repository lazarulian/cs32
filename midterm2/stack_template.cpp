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

template <typename T>
class Stack
{

public:

Stack() : head(nullptr), tail(nullptr), m_size(0)
{}

~Stack()
{
    Node *p;
    p = head;
    while (p != nullptr) // delete every node in the list
    {
        Node *n = p->next;
        delete p;
        p = n;
    }
}

void pop()
{
    if (m_size == 0)
        return;
    
    if (m_size == 1) {
        Node* p = head;
        head = nullptr;
        tail = nullptr;
        delete p;
    }

    else {
        Node* p = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete p;
    }
}


void push(T input)
{
    if (m_size == 0)
    {
        Node* p = new Node;
        p->value = input;
        p->next = nullptr;
        p->prev = nullptr;
        head = p;
        tail = p;
        m_size++;
    }
    else {
        Node* p = new Node;
        p->value = input;
        p->next = nullptr;
        p->prev = tail;
        tail->next = p;
        tail = p;
        m_size++;
    }
}

T front()
{
    if (m_size == 0)
        return -1;
    else
        return tail->value;
}
bool isEmpty() {
    return m_size == 0;
}

private:
int m_size;
struct Node {
    T value;
    Node* prev;
    Node* next;
};
Node* head;
Node* tail;
};

int main()
{
    Stack<int> p;

    assert(p.isEmpty() == true);
    assert(p.front() == -1);
    p.push(21);
    assert(p.front() == 21);
    assert(p.isEmpty() == false);
    p.push(44);
    p.push(69);
    assert(p.front() == 69);
    p.pop();
    assert(p.front() == 44);

    cout << "Passed all test cases" << endl;
    return 0;
}