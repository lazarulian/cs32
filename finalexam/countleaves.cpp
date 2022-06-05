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
    vector<Node*> children;
}; 

int countLeaves(Node *root)
{
    if (root == nullptr)
        return 0;
    int count = 0;
    if (root->children.size() == 0)
        return 1;
    else {
        for (int i = 0; i < root->children.size(); i++) 
        {
            count += countLeaves(root->children[i]);
        }
        return count;
    }
}

int main()
{

    Node* fatcrap = new Node;
    fatcrap->val = 0;
    Node* poop = new Node;
    Node* sleaze = new Node;
    Node* dude = new Node;
    Node* narwhal = new Node;
    Node* toad = new Node;

    fatcrap->children.push_back(poop);
    fatcrap->children.push_back(sleaze);
    fatcrap->children.push_back(dude);
    dude->children.push_back(narwhal);
    dude->children.push_back(toad);
    cout << fatcrap->children.size() << endl;
    cout << countLeaves(fatcrap) << endl;

    return 0;
}
