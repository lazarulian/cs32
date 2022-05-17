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
struct Node
{
    T value;
    Node* next;
    Node* prev;
};

template <typename T>
bool dom(Node<T> *head1, Node<T> *head2)
{
    if (head2 == nullptr)
    {
        return true;
    }
    if (head1 == nullptr)
        return false;
    if (head->value < head2->value)
        return false
    return dom(head1->next, head2->next);
}


int main()
{








return 0;
}