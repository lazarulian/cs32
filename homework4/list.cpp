#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Domain
{
public:
    Domain(string lbl) : m_label(lbl) {}
    string label() const { return m_label; }
    const vector<Domain *> &subdomains() const { return m_subdomains; }
    void add(Domain *d) { m_subdomains.push_back(d); }
    ~Domain();

private:
    string m_label;
    vector<Domain *> m_subdomains;
};

Domain::~Domain()
{
    for (size_t k = 0; k < m_subdomains.size(); k++)
        delete m_subdomains[k];
}

void listAll(const Domain *d, string path)
{ // Basic tree structure without even knowing it yet
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

void listAll(const Domain *d) // one-parameter overload
{
    if (d != nullptr)
        listAll(d, d->label());
}

int main()
{
    Domain *d1 = new Domain("ucla");
    d1->add(new Domain("cs"));
    d1->add(new Domain("ee"));
    d1->add(new Domain("math"));
    Domain *d2 = new Domain("caltech");
    d2->add(new Domain("math"));
    d2->add(new Domain("cs"));
    Domain *d3 = new Domain("edu");
    d3->add(d1);
    d3->add(d2);
    Domain *d4 = new Domain("com");
    d4->add(new Domain("microsoft"));
    d4->add(new Domain("apple"));
    Domain *d5 = new Domain("biz");
    Domain *root = new Domain("");
    root->add(d3);
    root->add(d4);
    root->add(d5);
    listAll(root);
    cout << "====" << endl;
    listAll(d3);
    cout << "====" << endl;
    listAll(d4);
    delete root;
}