void removeBad(list<Restaurant *> &li)
{ // Apurva Shah 705595011

    list<Restaurant *>::iterator it = li.begin();

    // While Loop for Iteration
    while (it != li.end())
    {
        if ((*it)->stars() <= 2)
        { // even condition
            delete *it;
            it = li.erase(it);
        }
        else
        { // else condition
            it++;
        }
    }
}