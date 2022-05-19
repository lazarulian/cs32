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

int powerofTwo(int x)
{
    if (x == 0)
        return 1;
    return powerofTwo(x-1) + powerofTwo (x-1);
}
int main()
{








return 0;
}