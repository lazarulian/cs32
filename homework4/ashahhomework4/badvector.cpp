void removeBad(vector<Restaurant *> &v)
{ // Apurva Shah 705595011
    for (size_t i = 0; i < v.size();)
    { // loop through the vector while controlling the size
        if (v[i]->stars()  <= 2) // even condition
        {
            delete v[i];
            v.erase(v.begin() + i);
        }
        else
            i++;
    }
}