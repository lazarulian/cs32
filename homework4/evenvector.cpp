#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

// Remove the even integers from v.
// It is acceptable if the order of the remaining even integers is not
// the same as in the original vector.
void removeEven(vector<int>& v)
{ // removes all of the even elements in the vector
    for (size_t i = 0; i < v.size();)
    { // loop through the vector while controlling the size
        if (v[i] % 2 == 0) // even condition
        {
            v.erase(v.begin()+i);
        }
        else
            i++;
    }
}

void test()
{
    int a[8] = {1, 7, 6, 5, 8, 4, 3, 2};
    vector<int> x(a, a + 8); // construct x from the array
    assert(x.size() == 8 && x.front() == 1 && x.back() == 2);
    removeEven(x);
    assert(x.size() == 4);
    sort(x.begin(), x.end());
    int expect[4] = {1, 3, 5, 7};
    for (int k = 0; k < 4; k++)
        assert(x[k] == expect[k]);
}

int main()
{
    test();
    cout << "Passed" << endl;
}