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


int helper(int x[], int length, int threshold, int sum)
{
    if (sum > threshold)
        return sum;
    if (length == 0)
        return -1;
    else {
        return helper(x+1, length-1, threshold, x[0]+sum);
    }
}

int sumOverThreshold(int x[], int length, int threshold)
{
    return helper(x, length, threshold, 0);
}


int main()
{



return 0;
}