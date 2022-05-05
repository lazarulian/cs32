#include <iostream>


using namespace std;

// how can we create this template for any item type
    // only useful for typed c++ classes

template<typename T>
T mimimum(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int k;
    cout << mimimum(k, 3.5);
}