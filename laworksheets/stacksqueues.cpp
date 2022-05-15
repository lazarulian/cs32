#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;


void findNextInts (const int Sequence[], int results[], int n)
{
    stack<int> values;
    stack<int> indexes;
    for (int i = 0; i < n; i++)
    {
        values.push(Sequence[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int curr = values.top();
        if (Sequence[i] > curr) {
            indexes.push(i);
            values.pop();
        }
    }

}



int main()
{

}