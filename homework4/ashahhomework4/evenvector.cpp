void removeEven(vector<int>& v)
{ // Apurva Shah 705595011
    // removes all of the even elements in the vector
    for (size_t i = 0; i < v.size();)
    { // loop through the vector while controlling the size
        if (v[i] % 2 == 0) // even condition
        {
            v.erase(v.begin()+i);
        }
        else
            i++;
    }
}