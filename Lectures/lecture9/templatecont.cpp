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

    list<int> li;

    li.push_back(10);
    li.push_back(10);
    li.push_back(10);
    li.push_back(10);
    li.push_back(10);
    li.push_front(20);

    for (list<int>::iterator p = li.begin(); p != li.end(); p++)
    {
        cout << *p << endl;
    }

    return 0;
}