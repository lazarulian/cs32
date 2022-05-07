#include <iostream>
#include <list>


using namespace std;

// iterators

int* find(int* b, int* e, const int& target)
{
    for (; b!= e; b++)
        if(*b == target)
            break;
    return b;
}

template<typename T>
T* find(T* b, T* e, const T& target)
{
    for (; b!= e; b++)
        if(*b == target)
            break;
    return b;
}

template<typename T, typename Iter>
Iter find(Iter b, Iter e, const T& target)
{
    for (; b!= e; b++)
        if(*b == target)
            break;
    return b;
}

int main()
{

    int a[5]= {1, 1, 1, 1, 1};
    int k;
    cin >> k;
    int* p = find(a, a+5, k);
    return 0;
}