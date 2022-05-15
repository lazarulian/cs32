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


int getPascals(int r, int c)
{
    if (c == 0 || c == r)
        return 1;
    return (getPascals(r-1, c-1) + getPascals(r-1, c));
}


int main()
{

cout << getPascals(4, 3) << endl;
assert(getPascals(2, 1) == 2);

return 0;
}