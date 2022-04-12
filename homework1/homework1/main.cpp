//
//  main.cpp
//  homework1
//
//  Created by Apurva Shah on 4/9/22.


    #include "Sequence.h"
    #include <iostream>
    #include <string>
    #include <cassert>
    using namespace std;

    // To test a Sequence of unsigned long, leave the #define line commented out;
    // to test a Sequence of string, remove the "//".

    // #define TEST_WITH_STRING

    #ifdef TEST_WITH_STRING
      const ItemType VAL[3] = { "injera", "lavash", "tortilla" };
    #else // assume unsigned long
      const ItemType VAL[3] = { 999, 10, 20 };
    #endif

    void test()
    {
        Sequence s;
        s.insert(0, VAL[1]);
        s.insert(0, VAL[2]);
        assert(s.size() == 2);
        ItemType x = VAL[0];
        assert(s.get(0, x) && x == VAL[2]);
        assert(s.get(1, x) && x == VAL[1]);
    }

    int main()
    {
        test();
        cout << "Passed all tests" << endl;
    }
