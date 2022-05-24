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

class Tree
{
private:
    struct Node
    {
        string name;
        vector<Node *> children;
    };
    Node root;

public:
    int countNodes(const Node *p);
    void printTree(const Node *p, int depth);
};

int Tree::countNodes(const Node *p)
{ // Recursively count the number of children in a tree

    if (p == nullptr)
        return 0;
    int total = 1; // to count the parent of the children themselves

    for (int i = 0; i < p->children.size(); i++)
        total += countNodes(p->children[i]);
    return total;
}

void Tree::printTree(const Node *p, int depth)
{
    if (p!= nullptr)
    {
        cout << string(2*depth, '') << p->name << endl;
        for (int k = 0; k < p->children.size(); k++)
        {
            printTree(p->children[k], depth+1);
        }
    }
}

main()
{

    return 0;
}