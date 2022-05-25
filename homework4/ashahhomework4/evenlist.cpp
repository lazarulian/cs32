void removeEven(list<int>& li)
{ // Apurva Shah 705595011
    // Declaration of Iterators
	list<int>::iterator it = li.begin();
	list<int>::iterator it2 = li.begin();

    // While Loop for Iteration
	while (it != li.end())
	{
		if (*it % 2 == 0)
		{ // even condition
			li.erase(it);
			it = it2;
		}
		else 
        { // else condition
			it2 = it;
			it++;
		}
	}
}