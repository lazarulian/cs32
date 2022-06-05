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



int countnum(const vector<string>& words, char c)
{ // o(N*K)

    int size = words.size();
    int total = 0;
    vector<string>::const_iterator it;
    for (it = words.begin(); it != words.end(); it++)
    {
        string temp_string = *it;
        for (int i = 0; i < temp_string.size(); i++)
        {
            if (temp_string[i] == c)
                total++;
            else
                continue;
        }
    }

    return total;
}


int main()
{








return 0;
}