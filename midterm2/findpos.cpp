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

int findPoshelper(int m_arr[], int n, int target);

int findPos(int m_arr[], int n, int target)
{
    if (findPoshelper(m_arr, n, target) != -1)
        return (n-findPoshelper(m_arr, n, target));
    else 
        return -1;
}

int findPoshelper(int m_arr[], int n, int target)
{

    if (m_arr[0] == target) {
        return n;
    }

    if (n == 0) {
        return -1;
    }

    return findPoshelper(m_arr+1, n-1, target);
}


int main()
{



int m_arr[] = {1,4,5,6,8,9};
assert(findPos(m_arr, 6, 4) == 1);
assert(findPos(m_arr, 6, 9) == 5);
assert(findPos(m_arr, 6, 23) == -1);

cout << "Passed all test cases!!" << endl;


return 0;
}