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
    Node* child[4];
};

int fixNegatives(Node* p)
{

    if (p == nullptr)
        return 0;
    int count = 0;
    if (p->data < 0) {
        p->data = 0;
        count++;
    }
    for (int i = 0; i < 4; i++)
        count += fixNegatives(p->child[i]);
    return count;
}

int main()
{


return 0;
}