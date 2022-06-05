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
    int value;
    Node *left;
    Node *right;
};

int findBST(Node *root, int target)
{
    Node *parent = nullptr;
    Node *curr = root;

    while (curr != nullptr)
    {
        if (target == curr->value)
            return curr->value;
        if (target < curr->value)
        {
            parent = curr;
            curr = curr->left;
        }
        else if (target > curr->value)
        {
            parent = curr;
            curr = curr->right;
        }
    }
    return -1;
}


bool Search(int v, Node *root)
{
    Node *ptr = root;
    while (ptr != nullptr)
    {
        if (v == ptr->value)
            return true;
        else if (v < ptr->value)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return false; // nope
}

bool Search(int v, Node *ptr)
{
    if (ptr == nullptr)
        return false; // nope
    else if (v == ptr->value)
        return (true); // found!!!
    else if (v < ptr->value)
        return Search(V, ptr->left);
    else
        return Search(V, ptr->right);
}

void insert(const std::string &value)
{
    if (m_root == NULL)
        Node *cur = m_root;
    for (;;)
    {
        m_root = new Node(value);
        {
            if (value < cur->value)
                return;
        }
        return;
        if (value == cur->value)
        {
            if (cur->left != NULL)
                cur = cur->left;
            else
            {
                cur->left = new Node(value);
                return;
            }
        }
        else if (value > cur->value)
        {
            if (cur->right != NULL)
                cur = cur->right;
            else
            {
                cur->right = new Node(value);
                return;
            }
        }
    }
} // insertion into binary search tree

void deleteBST(Node *root, int target)
{
    Node *parent = nullptr;
    Node *curr = root;

    // finding the deletion
    while (curr != nullptr)
    {
        if (target == curr->value)
            break;
        if (target < curr->value)
        {
            parent = curr;
            curr = curr->left;
        }
        else if (target > curr->value)
        {
            parent = curr;
            curr = curr->right;
        }
    }
    // completing the deletion

    // leaf node
    if (curr->right == nullptr && curr->left == nullptr)
    {
        if (parent == nullptr)
        {
            root = nullptr;
            delete curr;
        }

        else if (curr->value > parent->value)
        {
            parent->right = nullptr;
            delete curr;
        }
        else
        {
            parent->left = nullptr;
            delete curr;
        }
        return;
    }

    // one leaf
    else if (curr->right == nullptr && curr->left != nullptr)
    {
        if (parent == nullptr)
        {
            root = curr->left;
            delete curr;
        }
        else if (parent->left == curr)
        {
            parent->left = curr->left;
            delete curr;
        }
        else
        {
            parent->right = curr->left;
        }
        return;
    }

    else if (curr->right != nullptr && curr->left == nullptr)
    {
        if (parent == nullptr)
        {
            root = curr->right;
            delete curr;
        }
        else if (parent->left == curr)
        {
            parent->left = curr->right;
            delete curr;
        }
        else
        {
            parent->right = curr->right;
            delete curr;
        }
        return;
    }

    // two leaves
    Node *ptr = cur->left;
    Node *ptrparent = curr->left;
    while (ptr->right != nullptr)
        ptr = ptr->right;
    while (ptrparent->right->right != nullptr)
        ptrparent = ptrparent->right;
    curr->value = ptr->value;
    if (ptrparent->left == ptr)
        ptrparent->left = nullptr;
    else
        ptrparent->right = nullptr;
    delete ptr;
}

int main()
{

    return 0;
}