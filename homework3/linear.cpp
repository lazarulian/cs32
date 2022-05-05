// linear.cpp Apurva Shah 705595011
// exploring predicate functions within c++

bool allFalse(const string a[], int n)
{ // Return false if the somePredicate function returns true for at least one of the array elements; return true otherwise.
    // checking for small value
    if (n <= 0)
    {
        return true;
    }

    if (somePredicate(a[0]) == true)
    {
        return false;
    }
    return allFalse(a + 1, n - 1);
}

int countFalse(const string a[], int n)
{ // Return the number of elements in the array for which the somePredicate function returns false.
    int counter = 0;
    if (n <= 0)
        return 0;
    // checks the last elelement and then recursively iterates backwards through the array
    if (somePredicate(a[n - 1]) == false)
    {
        return 1 + (countFalse(a, n - 1));
    }
    else
    {
        return (countFalse(a, n - 1));
    }
}

int firstFalse(const string a[], int n)
{ // Return the subscript of the first element in the array for which the somePredicate function returns false.
  // If there is no such element, return -1.

    if (n <= 0)
        return -1;
    // checking to see if the first value is false
    if (somePredicate(a[0]) == false)
        return 0;
    int temp_pos = firstFalse(a + 1, n - 1);
    // checking for whether we have reached the end of the index
    if (temp_pos == -1)
        return -1;
    return 1 + temp_pos;
}

int positionOfLeast(const string a[], int n)
{ // Return the subscript of the least string in the array (i.e.) return the smallest subscript m such that a[m] <= a[k] for all
  // k from 0 to n-1).  If the function is told that no strings are to be considered in the array, return -1.
    if (n < 0)
        return -1;
    // base case that terminates recursion
    if (n == 0)
        return 0;
    // recursive calls to the function
    int temp_index = positionOfLeast(a, n - 1);

    if (a[temp_index] <= a[n - 1])
    { // checks whether one below temp index is bigger or smaller
        return positionOfLeast(a, n - 1);
    }
    else
    { // case that it is the smallest
        return n - 1;
    }
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "merida" "tiana" "raya" "belle" "tiana" "raya" "moana"
// then the function should return true if a2 is
//    "tiana" "belle" "moana"
// or
//    "tiana" "raya" "raya"
// and it should return false if a2 is
//    "tiana" "moana" "belle"
// or
//    "merida" "belle" "belle"
bool has(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0) // the base case
		return true;
    
	if (n1 < n2) // terminates usually
		return false;
	if (a1[0] == a2[0])
		return has(a1 + 1, n1 - 1, a2 + 1, n2 - 1); // recursive call
	return has(a1 + 1, n1 - 1, a2, n2); // second recursive call if the if doesn't branch
}