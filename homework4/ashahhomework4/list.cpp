void listAll(const Domain *d, string path)
{ // Apurva Shah 705595011
    // Basic tree structure without even knowing it yet
    // Base Case
    if (d->subdomains().size() == 0)
    {
        cout << path << endl;
        return;
    }

    else if (path != "")
    {
        path = "." + path;
    }

    // Loop and Recursive Call
    for (vector<Domain *>::const_iterator it = d->subdomains().begin(); it != d->subdomains().end(); it++)
    {
        listAll(*it, (*it)->label() + path);
    }
}