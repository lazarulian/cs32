#include <iostream>

using namespace std;

struct Node 
{
    int value;
    Node* next; // pointer to a node
    // Node next; // will not compile
    Node* head;
};


int main() {

    int a[100];
    int n;

    cin >> n;

    int* b = new int[n];

    // Linked Lists

    Node* p;
    for (p = head; p != nullptr && p != 18; p = p->value)


    Node* tobedeleted = p->next;
    p->next = p->next->next;
    tobedeleted->next;
    delete tobedeleted;

    return 0;
}