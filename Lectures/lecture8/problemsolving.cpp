#include <iostream>

using namespace std;


int getMidpoint(int b, int e)
{
    return ((b+e)/2);
}

void merge(string ar[], int a, int b, int e)
{

}
void recursiveSort(string* arr[], int b, int e) {
    // recursively sorts an array
    int mid = getMidpoint(b, e);
    recursiveSort(a, b, mid);
    recursiveSort(a, mid, e);
    merge(a, b, mid, e);
}

int main()
{
    

    return 0;
}