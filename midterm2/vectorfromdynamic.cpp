#include <iostream>
#include <string>
#include <cassert>

using namespace std;

template<typename T>
class Vector
{
    public:
    Vector()
    {
        m_arr = new T[0];
        size = 0;
        capacity = 0;
    }

    ~Vector()
    {
        delete [] m_arr;
    }

    void pushback(T input)
    {
        if (size == capacity)
        {
            // declaring new array
            T* temp_arr = new T[size+10];
            // copying items
            for (int i = 0; i < size; i++)
            {
                temp_arr[i] = m_arr[i];
            }
            // deleting old array
            delete [] m_arr;
            // reassigning the temp_arr
            m_arr = temp_arr;
            capacity += 10;
        }
        m_arr[size] = input;
        size++;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << m_arr[i] << endl;
        }
    }

    void getSizeCap()
    {
        cout << "The size of the array is: " << size << endl;
        cout << "The capacity of the array is: " << capacity << endl;
    }

    private:
    T* m_arr;
    int size;
    int capacity;

};



int main()
{

    Vector<int> a;
    a.getSizeCap();
    a.pushback(5);
    a.getSizeCap();
    a.print();



    return 0;
}