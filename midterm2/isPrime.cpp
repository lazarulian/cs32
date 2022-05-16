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

bool isPrimeHelper(int n, int numeric);


bool isPrime (int n)
{

    return isPrimeHelper(n, 9);

}

bool isPrimeHelper(int n, int numeric)
{
    if (numeric == 1)
        return true;
    if (n % numeric == 0)
        return false;
    return isPrimeHelper(n, numeric-1);
}

int main()
{



assert(isPrime(13) == true);
assert(isPrime(4) == false);
assert(isPrime(47) == true);
assert(isPrime(83) == true);
assert(isPrime(63) == false);

cout << "Passed all test cases" << endl;


return 0;
}