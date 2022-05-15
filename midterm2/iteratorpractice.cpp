#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;


int main()
{

    list<string> n;

    n.push_back("hybrid");
    n.push_back("appear");
    n.push_back("front");
    n.push_back("back");

    cout << "List before the deletion" << endl;

    for (list<string>::const_iterator it = n.cbegin(); it != n.cend(); ++it)
        cout << *it << endl;

    for (list<string>::iterator it = n.begin(); it != n.end(); it++) {
        if (*it == "appear")
            it = n.erase(it);
    }

    cout << "List after the deletion" << endl;

    for (list<string>::const_iterator it = n.cbegin(); it != n.cend(); it++) {
        cout << *it << ", ";
    }









    return 0;
}