#include "Sequence.h"
#include <iostream>
#include <cassert>

int main()
{
    const int maxFill = 20;

    // Default constructor
    {
        Sequence test;
        assert(test.empty() == true);
        assert(test.size() == 0);
    }
    // Copy constructor
    {
        Sequence base;
        for (int i = 0; i < maxFill; i++)
            assert(base.insert(i) == i);
        Sequence test = base;
        for (int i = 0; i < maxFill; i++)
            assert(test.find(i) == i);
        base.erase(maxFill - 1);
        test.erase(0);
        for (int i = 0; i < maxFill - 1; i++)
        {
            assert(base.find(i) == i);
            assert(test.find(i + 1) == i);
        }
    }
    // Assignment operator
    {
        Sequence base, test;
        // Create different Sequences
        for (int i = 0; i < maxFill; i++)
        {
            assert(base.insert(i) == i);
            assert(test.insert(i + maxFill) == i);
        }
        // Validate different Sequences
        for (int i = 0; i < maxFill; i++)
        {
            assert(base.find(i) == i);
            assert(test.find(i + maxFill) == i);
        }
        // Check if Sequences are the same after assignment
        test = base;
        for (int i = 0; i < maxFill; i++)
        {
            assert(base.find(i) == i);
            assert(test.find(i) == i);
        }
        // Check if modifying one does not modify the other
        base.erase(maxFill - 1);
        test.erase(0);
        for (int i = 0; i < maxFill - 1; i++)
        {
            assert(base.find(i) == i);
            assert(test.find(i + 1) == i);
        }

        // Assign to empty
        Sequence testFull, testEmpty;
        for (int i = 0; i < maxFill; i++)
            assert(testFull.insert(i) == i);
        for (int i = 0; i < maxFill; i++)
            assert(testFull.find(i) == i);
        testFull = testEmpty;
        for (int i = 0; i < maxFill; i++)
        {
            assert(testFull.find(i) == -1);
            assert(testEmpty.find(i) == -1);
        }

        // Aliasing
        Sequence testAlias;
        for (int i = 0; i < maxFill; i++)
            assert(testAlias.insert(i) == i);
        for (int i = 0; i < maxFill; i++)
            assert(testAlias.find(i) == i);
        testAlias = testAlias;
        for (int i = 0; i < maxFill; i++)
            assert(testAlias.find(i) == i);
    }
    // empty(), size()
    {
        Sequence test;
        assert(test.empty());
        assert(test.size() == 0);
        for (int i = 0; i < maxFill; i++)
        {
            assert(test.insert(i) == i);
            assert(test.empty() == false);
            assert(test.size() == i + 1);
        }
    }
    // insert(pos, value)
    {
        Sequence test;
        int mid = 0;
        for (int i = 0; i < maxFill; i++)
        {
            assert(test.insert(mid, i) == mid);
            assert(test.size() == i + 1);
            mid = test.size() / 2;
        }
        for (int i = 0; i < mid; i++)
        {
            assert(test.find(2 * i + 1) == i);
            assert(test.find(2 * i) == maxFill - 1 - i);
        }
    }
    // insert(value)
    {
        Sequence test1, test2;
        for (int i = 0; i < maxFill; i++)
        {
            assert(test1.insert(i) == i);
            assert(test2.insert(maxFill - i - 1) == 0);
            assert(test1.size() == i + 1);
            assert(test2.size() == i + 1);
        }
        for (int i = 0; i < maxFill; i++)
        {
            assert(test1.find(i) == i);
            assert(test2.find(i) == i);
        }
    }
    // erase(pos)
    {
        Sequence test;

        // Remove from end
        for (int i = 0; i < maxFill; i++)
            assert(test.insert(i) == i);
        for (int i = 0; i < maxFill; i++)
        {
            assert(test.erase(test.size() - 1));
            assert(test.size() == maxFill - 1 - i);
            for (int j = 0; j < test.size(); j++)
                assert(test.find(j) == j);
        }

        // Remove from front
        for (int i = 0; i < maxFill; i++)
            assert(test.insert(i) == i);
        for (int i = 0; i < maxFill; i++)
        {
            assert(test.erase(0));
            assert(test.size() == maxFill - 1 - i);
            for (int j = 0; j < test.size(); j++)
                assert(test.find(j + i + 1) == j);
        }
    }
    // remove(value)
    {
        Sequence test;
        ItemType arr[] = { 0, 7, 1, 7, 2, 7, 3, 7, 4, 7 };
        for (int i = 0; i < 10; i++)
            assert(test.insert(i, arr[i]) == i);
        assert(test.remove(7) == 5);
        for (int i = 0; i < 5; i++)
            assert(test.find(i) == i);
        assert(test.remove(7) == 0);
    }
    // get(pos, value)
    {
        Sequence test;
        ItemType IT;
        for (int i = 0; i < maxFill; i++)
            assert(test.insert(i) == i);
        for (int i = 0; i < maxFill; i++)
        {
            assert(test.get(i, IT));
            assert(IT == i);
        }
        assert(test.get(-1, IT) == false);
        assert(test.get(test.size(), IT) == false);
    }
    // set(pos, value)
    {
        Sequence test;
        for (int i = 0; i < maxFill; i++)
            assert(test.insert(i) == i);
        for (int i = 0; i < maxFill; i++)
            assert(test.find(i) == i);
        for (int i = 0; i < maxFill; i++)
            assert(test.set(i, i + maxFill));
        assert(test.set(-1, 1) == false);
        assert(test.set(test.size(), 1) == false);
        for (int i = 0; i < maxFill; i++)
            assert(test.find(i + maxFill) == i);
    }
    // swap(Seq1, Seq2)
    {
        Sequence test1, test2;
        for (int i = 0; i < maxFill; i++)
            assert(test1.insert(i) == i);
        for (int i = 0; i < 2 * maxFill; i++)
            assert(test2.insert(i + maxFill) == i);
        assert(test1.size() == maxFill);
        assert(test2.size() == maxFill * 2);

        for (int i = 0; i < maxFill; i++)
            assert(test1.find(i) == i);
        for (int i = 0; i < 2 * maxFill; i++)
            assert(test2.find(i + maxFill) == i);

        test1.swap(test2);
        assert(test1.size() == maxFill * 2);
        assert(test2.size() == maxFill);
        for (int i = 0; i < maxFill; i++)
            assert(test2.find(i) == i);
        for (int i = 0; i < 2 * maxFill; i++)
            assert(test1.find(i + maxFill) == i);

        // Empty swap
        Sequence testFull, testEmpty;
        for (int i = 0; i < maxFill; i++)
            assert(testFull.insert(i) == i);
        for (int i = 0; i < maxFill; i++)
            assert(testFull.find(i) == i);
        assert(testFull.size() == maxFill);
        assert(testEmpty.empty());

        testFull.swap(testEmpty);
        assert(testFull.empty());
        assert(testEmpty.size() == maxFill);
        for (int i = 0; i < maxFill; i++)
        {
            assert(testFull.find(i) == -1);
            assert(testEmpty.find(i) == i);
        }

        // Aliasing
        Sequence testAlias;
        for (int i = 0; i < maxFill; i++)
            assert(testAlias.insert(i) == i);
        testAlias.swap(testAlias);
        for (int i = 0; i < maxFill; i++)
            assert(testAlias.find(i) == i);
    }
    // subsequence
    {
        Sequence t01, t02;
        ItemType t01a[] = { 1, 2, 2, 3, 2, 3, 4, 5 };
        ItemType t02a[] = { 2, 3, 4, 5 };
        for (int i = 0; i < 8; i++)
            t01.insert(i, t01a[i]);
        for (int i = 0; i < 4; i++)
            t02.insert(i, t02a[i]);
        assert(subsequence(t01, t02) == 4);

        Sequence t11, t12;
        ItemType t11a[] = { 1, 2, 2, 3, 2, 3, 4, 5 };
        ItemType t12a[] = { 2, 3, 4 };
        for (int i = 0; i < 8; i++)
            t11.insert(i, t11a[i]);
        for (int i = 0; i < 3; i++)
            t12.insert(i, t12a[i]);
        assert(subsequence(t11, t12) == 4);

        Sequence t21, t22;
        ItemType t21a[] = { 1, 2, 2, 3, 5 };
        ItemType t22a[] = { 2, 3, 4, 5 };
        for (int i = 0; i < 5; i++)
            t21.insert(i, t21a[i]);
        for (int i = 0; i < 4; i++)
            t22.insert(i, t22a[i]);
        assert(subsequence(t21, t22) == -1);

        Sequence t31, t32;
        ItemType t31a[] = { 1, 2, 2, 3, 5 };
        for (int i = 0; i < 5; i++)
            t31.insert(i, t31a[i]);
        assert(subsequence(t31, t32) == -1);

        Sequence t41, t42;
        ItemType t42a[] = { 2, 3, 4, 5 };
        for (int i = 0; i < 4; i++)
            t42.insert(i, t42a[i]);
        assert(subsequence(t41, t42) == -1);
    }
    // interleave
    {
        Sequence t01, t02, t03;
        for (int i = 0; i < 5; i++)
        {
            t01.insert(2 * i);
            t02.insert(2 * i + 1);
            t03.insert(-1);
        }
        interleave(t01, t02, t03);
        assert(t03.size() == 10);
        for (int i = 0; i < 10; i++)
            assert(t03.find(i) == i);

        Sequence t11, t12, t13;
        ItemType t11a[] = { 1, 2, 3, 4, 5 };
        ItemType t12a[] = { 6, 7, 8 };
        ItemType t13a[] = { 1, 6, 2, 7, 3, 8, 4, 5 };
        for (ItemType elem : t11a)
            t11.insert(elem);
        for (ItemType elem : t12a)
            t12.insert(elem);
        interleave(t11, t12, t13);
        assert(t13.size() == 8);
        int i1 = 0;
        for (ItemType elem : t13a)
        {
            ItemType temp;
            t13.get(i1, temp);
            assert(temp == elem);
            i1++;
        }

        Sequence t21, t22, t23;
        ItemType t21a[] = { 6, 7, 8 };
        ItemType t22a[] = { 1, 2, 3, 4, 5 };
        ItemType t23a[] = { 6, 1, 7, 2, 8, 3, 4, 5 };
        for (ItemType elem : t21a)
            t21.insert(elem);
        for (ItemType elem : t22a)
            t22.insert(elem);
        interleave(t21, t22, t23);
        assert(t23.size() == 8);
        int i2 = 0;
        for (ItemType elem : t23a)
        {
            ItemType temp;
            t23.get(i2, temp);
            assert(temp == elem);
            i2++;
        }

        Sequence t31, t32, t33;
        ItemType t31a[] = { 1, 2, 3, 4, 5 };
        for (ItemType elem : t31a)
            t31.insert(elem);
        interleave(t31, t32, t33);
        assert(t33.size() == 5);
        int i3 = 0;
        for (ItemType elem : t31a)
        {
            ItemType temp;
            t33.get(i3, temp);
            assert(temp == elem);
            i3++;
        }

        Sequence t41, t42, t43;
        ItemType t42a[] = { 1, 2, 3, 4, 5 };
        for (ItemType elem : t42a)
            t42.insert(elem);
        interleave(t41, t42, t43);
        assert(t33.size() == 5);
        int i4 = 0;
        for (ItemType elem : t42a)
        {
            ItemType temp;
            t43.get(i4, temp);
            assert(temp == elem);
            i4++;
        }

        Sequence t51, t52, t53;
        interleave(t51, t52, t53);
        assert(t53.size() == 0);
    }
    std::cout << "           ',\n        .-`-,\\__\n          .\"`   `,\n        .'_.  ._  `;.\n    __ / `      `  `.\\ .--.\n   /--,| 0)   0)     )`_.-,)\n  |    ;.-----.__ _-');   /\n   '--./         `.`/  `\"`\n      :   '`      |.\n      | \     /  //\n       \\ '---'  /'\n        `------' \\\n         _/       `--..." << std::endl;
}
