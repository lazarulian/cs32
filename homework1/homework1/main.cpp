//
//  main.cpp
//  homework1
//
//  Created by Apurva Shah on 4/9/22.
//

#include <iostream>
#include <string>
#include "Sequence.h"

using namespace std;

int main() {
    
    
    
    Sequence s1;
       s1.insert(0, "paratha");
       s1.insert(0, "focaccia");
    string x;
    cout << s1.get(0, x) << endl;
    cout << s1.get(1, x) << endl;
       Sequence s2;
       s2.insert(0, "roti");
       s1.swap(s2);
        assert(s1.size() == 1);
        assert(s1.find("roti")== 0);
        assert(s2.size() == 2);
        assert(s2.find("foccacia") == 0);
        assert(s2.find("paratha") == 1);
    
}
