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
    Node *left, *right;
};

bool areIdentical(Node * root1, Node *root2)
{
    /* base cases */
    if (root1 == NULL && root2 == NULL)
        return true;
 
    if (root1 == NULL || root2 == NULL)
        return false;
 
    /* Check if the data of both roots is
    same and data of left and right
    subtrees are also same */
    return (root1->val == root2->val &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}

bool isSubtree(Node *T, Node *S)
{
    /* base cases */
    if (S == NULL)
        return true;
 
    if (T == NULL)
        return false;
 
    /* Check the tree with root as current node */
    if (areIdentical(T, S))
        return true;
 
    /* If the tree with root as current
    node doesn't match then try left
    and right subtrees one by one */
    return isSubtree(T->left, S) ||
        isSubtree(T->right, S);
}


int main()
{

    return 0;
}