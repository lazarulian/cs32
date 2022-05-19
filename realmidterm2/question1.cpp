#include <iostream>
#include <list>
#include <vector>
#include <cassert>
using namespace std;

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE END OF THE smallbig FUNCTION

bool smallbig(list<int> &c1, vector<int> &c2)
{
    if (c1.size() != c2.size())
        return false;
    
    list<int>::iterator it1;
    vector<int>::iterator it2;
    it1 = c1.begin();
    it2 = c2.begin();

    while (it2 != c2.end())
    {
        if (*it1 == *it2)
        {
            it1++;
            it2++;
            continue;
        }

        else if (*it1 > *it2)
        {
            int temp = *it1;
            *it1 = *it2;
            *it2 = temp;
            it1++;
            it2++;
            continue;
        }
        else {
            it1++;
            it2++;
            continue;
        }
    }
    return true;
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE START OF THE smallbig FUNCTION

int main()
{
    list<int> li;
    vector<int> v;
    assert(smallbig(li, v));
    
    int x[4] = { 7, -5, 3, 6 };
    int y[4] = { 4,  1, 3, 2 };
    int expectx[4] = { 4, -5, 3, 2 };
    int expecty[4] = { 7,  1, 3, 6 };
    list<int> small(x, x+4);
    vector<int> big(y, y+4);
    assert(smallbig(small, big));
    list<int> expectsmall(expectx, expectx+4);
    vector<int> expectbig(expecty, expecty+4);
    assert(small == expectsmall  &&  big == expectbig);

    vector<int> big2(y, y+3);
    assert( ! smallbig(small, big2));  // different num of elements

    vector<int> fatty;
    fatty.push_back(22);
    fatty.push_back(1);
    fatty.push_back(21);
    fatty.push_back(14);
    fatty.push_back(9);

    list<int> giant;
    giant.push_back(22);
    giant.push_back(1);
    giant.push_back(21);
    giant.push_back(14);

    assert(smallbig(giant, fatty) == false);


    cout << "All tests succeeded" << endl;
}