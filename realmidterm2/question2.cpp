#include <iostream>
#include <cassert>
using namespace std;

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE END OF THE product FUNCTION


int product(int a, int b) {
    if (b > 0) {
        return a + product(a, b - 1);
    }
    else if (b < 0) {
        return -a + product(a, b + 1);
    }

    return 0;
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE START OF THE product FUNCTION

int main()
{   
    assert(multiply(7, 5) == 35);
    assert(multiply(-4, 8) == -32);
    assert(multiply(-4, -4) == 16);
    assert(multiply(0, 0) == 0);
    assert(multiply(8, -4) == -32);

    cout << "All tests succeeded" << endl;
}