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


// declaration of the binary search tree

struct Data
{
  int key;
  int value;
};
struct Node
{ // The right subtree has values that are larger and the 
  // left subtree has items that are smaller than the node
  Node* left;
  Node* right;
  Data data;
}

void printTree(const Node* p)
{
  if (p != nullptr)
  {
    printTree(left);
    printTree(right);
  }
  return;
}



int main()
{








return 0;
}