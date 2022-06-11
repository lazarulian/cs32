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

int getGreatestPath(Node *head)
{
    if (head == nullptr)
        return 0;
    int leftMax = getGreatestPath(head->left);
    int rightMax = getGreatestPath(head->right);

    if (leftMax > rightMax)
        return head->val + leftMax;
    else
        return head->val + rightMax;
}