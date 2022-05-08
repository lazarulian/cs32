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


int main()
{

    

    return 0;
}