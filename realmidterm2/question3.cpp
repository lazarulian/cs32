#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
    int   data;
    Node* next[3];
};

int fixNegatives(Node* p)
{
    // reaches the end
    if (p == nullptr)
        return 0;
    int count = 0;
    if (p->data < 0) {
        p->data = 0;
        count++;
    }
    for (int i = 0; i < 4; i++)
        count += fixNegatives(p->next[i]);
    return count;
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE END OF THE countGreaters FUNCTION

int countGreaters(const Node* p)
{
    if (p == nullptr)
        return 0;
    int count = 0;
    bool isGreater = false;
    for (int i = 0; i < 3; i++)
    {
        if (p->next[i] == nullptr)
            continue;
        if (p->data > p->next[i]->data)
            isGreater = true;
    }
    if (isGreater == true)
        count++;
    for (int i = 0; i < 3; i++)
        count += countGreaters(p->next[i]);
    return count;
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE START OF THE countGreaters FUNCTION

Node* makeNode(int d)
{
     Node* p = new Node;
     p->data = d;
     for (int k = 0; k < 3; k++)
         p->next[k] = nullptr;
     return p;
}

int main()
{
      // Build the 3-group pictured in the problem as an example

    Node* n2 = makeNode(2);
    n2->next[2] = makeNode(7);
 
    Node* n8 = makeNode(8);
    n8->next[1] = n2;
     
    Node* n5 = makeNode(5);
    n5->next[0] = makeNode(2);
    n5->next[2] = makeNode(1);
     
    Node* n3 = makeNode(3);
    n3->next[1] = n5;
 
    Node* start = makeNode(6);
    start->next[0] = n8;
    start->next[1] = makeNode(9);
    start->next[2] = n3;
    
      // Test countGreaters with that 3-group
    assert(countGreaters(start) == 3);
    assert(countGreaters(start->next[2]) == 1);
    assert(countGreaters(nullptr) == 0);
    cout << "All tests succeeded" << endl;

      // Clean up the 3-group

    delete n2->next[2];
    delete n2;
    delete n8;
    delete start->next[1];
    delete n5->next[0];
    delete n5->next[2];
    delete n5;
    delete n3;
    delete start;
}