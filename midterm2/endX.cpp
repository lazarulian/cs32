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

string moveAtEnd(string s, int i, int l, string start);

string endX(string str)
{
    if (str.length() <= 1) // base case: no x’s to shift to end
        return str;
    if (str[0] == 'x')
        return endX(str.substr(1)) + 'x'; // reduce: handle str[0]
        // first
    else 
        return str[0] + endX(str.substr(1));
}

int main()
{

    cout << endX("xrxe") << endl;
    assert(endX("xrxe") == "rexx");
    cout << "Passed all test cases!!" << endl;

    return 0;
}