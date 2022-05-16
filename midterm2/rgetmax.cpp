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

int helper(int a[], int n, int currmax)
{
    if (a[0] > currmax)
        currmax = a[0];
    if (n == 0)
        return currmax;
    else {
        return helper(a+1, n-1, currmax);
    }
}

int getMax (int a[], int n)
{
int first_num = a[0];
return helper(a, n, first_num);
}


int main()
{


int m_arr[5] = {23, 69, 44, 26, 22};

assert(getMax(m_arr, 5) == 69);
cout << "Passed all test cases!!" << endl;

return 0;
}