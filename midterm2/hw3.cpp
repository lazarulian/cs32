#include <iostream>
#include <cassert>
#include <string>
using namespace std;

bool somePredicate(string s)
{
    return s.empty();
}

// Return false if the somePredicate function returns true for at
// least one of the array elements; return true otherwise.
bool allFalse(const string a[], int n)
{
    if (n <= 0)
        return true;

    if (somePredicate(a[0]) == true)
        return false;

    return allFalse(a + 1, n - 1);
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
    if (n <= 0)
        return 0;
    if (somePredicate(a[0]) == false)
        return 1;
    countFalse(a+1, n-1);
}


// UPE Slides



int main()
{
    return 0;
}