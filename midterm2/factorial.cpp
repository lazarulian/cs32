#include <iostream>
#include <cassert>
#include <string>

using namespace std;


int solveFactorial(int n)
{
    if (n == 0)
        return 1;

    return (n * solveFactorial(n-1));
}

int solveFibbonaci(int n)
{
    if (n == 0)
        return n;
    if (n == 1)
        return n;
    return(solveFibbonaci(n-1)+solveFibbonaci(n-2));
}

void printNatural (int n)
{
    if (n > 50)
        return;
    else {
        cout << n << endl;
        printNatural(n+1);
    }
}

int sumRange(int start, int end)
{
    if (end == start)
        return end;

    else {
        return (end+sumRange(start, end-1));
    }
}

void printArray(int m_arr[], int n)
{// Prints the elements of the array
    if (n == 0)
        return;
    cout << *m_arr << endl;
    return (printArray(m_arr+1, n-1));    
}

int sumArray(int m_arr[], int n)
{
    if (n == 0)
        return 0;
    return (*m_arr + sumArray(m_arr+1, n-1));
}

bool isPalendrome(string input)
{
    if (input.length() == 0 || input.length() == 1)
        return true;
    if (input[0] != input[input.length()-1])
        return false;
    
    return isPalendrome(input.substr(1, input.length()-2));
}

int main()
{
    // Solving Factorials
    assert(solveFactorial(4) == 24);
    assert(solveFactorial(3) == 6);

    // Solving the Fibonnaci Sequence
    assert(solveFibbonaci(1) == 1);
    assert(solveFibbonaci(0) == 0);
    assert(solveFibbonaci(3) == 2);
    assert(solveFibbonaci(9) == 34);
    
    // Sum Range
    assert(sumRange(1, 3) == 6);
    // Print the Array
    int test_arr[5] = {1, 2, 3, 4, 5};
    // printArray(test_arr, 5);

    // Sum of the Array
    assert(sumArray(test_arr, 5) == 15);

    // IsPalendrome
    assert(isPalendrome("racecar") == true);
    assert(isPalendrome("batman") == false);
    cout << "Passed all test cases!" << endl;

    return 0;
    
}