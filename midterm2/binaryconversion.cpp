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


void printBinary(int n)
{

    if (n == 0)
        return;
    else {
       if ((n%10)%2 == 0){
           cout << 0 << endl;
       }
       else {
           cout << 1 << endl;
       }
       return printBinary(n /= 10);
    }
}

int main()
{

printBinary(43);

return 0;
}