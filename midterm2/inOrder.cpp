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

void printArrayInOrder(const double a[], int n)
{
    if (n == 0)
        return;

    cout << a[0] << endl;

    printArrayInOrder(a+1, n-1);
}

void printArrayInReverse(const double a[], int n)
{
    if (n == 0)
        return;
    
    printArrayInReverse(a+1, n-1);
    cout << a[0] << endl;
}


int main()
{


double m_arr[5] = {1, 2, 3, 4, 5};
printArrayInOrder(m_arr, 5);
printArrayInReverse(m_arr, 5);

return 0;
}