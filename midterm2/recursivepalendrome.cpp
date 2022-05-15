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

bool isPalindrome(string foo)
{
    int len = foo.length();
    if (len <= 1)
        return true;
    if (foo[0] != foo[len - 1])
        return false;
    return isPalindrome(foo.substr(1, len - 2));
}

int main()
{

    return 0;
}