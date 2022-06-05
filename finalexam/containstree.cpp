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
    int val;
    Node *left;
    Node *right;
};

bool treeContains(Node *head, int n)
{
    if (head == nullptr)
    {
        return false;
    }
    else if (head->val == n && head != nullptr)
        return true;
    else
    {
        return treeContains(head->left, n) || treeContains(head->right, n);
    }
}


int main()
{

    return 0;
}