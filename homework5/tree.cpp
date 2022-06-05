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


class BSTNodes
{
    public:
    void insertBST(Node* parent, int value)
    {
        // Tree is Empty
        if parent is nullptr, parent->data is value
        // Tree has value already
        if node = parent, 
            return
        // Down the Right
        else if (value > parent->data)
            return (insertBST(parent->right, value))
        // Down the Left
        else if(value < parent->data)
            return (insertBST(parent->left, value))
    }
    private:
    struct Data
    {
        int Data;
        int Key;
    };
    struct Node
    {
        Node* head;
        Node* left;
        Node* right;
        Data data;
    };

};


int main()
{








return 0;
}