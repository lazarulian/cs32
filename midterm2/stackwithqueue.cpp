#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

class Stack {
public:
   bool empty() const;
   int size() const;
   int top();
   void push(int value);
   void pop();

private:
   queue<int> q;
};

bool Stack::empty() const 
{
    return q.empty();
}

int Stack::size() const
{
    return q.size();
}

int Stack::top()
{
    return q.back();
}

void Stack::push(int value)
{
    q.push(value);
}

void Stack::pop()
{
    int size = q.size();
    for (int i = 0; i < size-1; i++)
    {
        int temp = q.front();
        q.push(temp);
        q.pop();
    }
    q.pop();
}


int main()
{
    Stack nameless;

    assert(nameless.empty() == true);
    nameless.push(1);
    assert(nameless.empty() == false);
    assert(nameless.top() == 1);
    nameless.pop();
    assert(nameless.empty() == true);
    nameless.push(23);
    nameless.push(54);
    nameless.push(69);
    assert(nameless.top() == 69);
    nameless.pop();
    assert(nameless.top() == 54);
    cout << "Passed all test cases!!!" << endl;
}