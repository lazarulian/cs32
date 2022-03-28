#include <iostream>
#include <cstdlib>

using namespace std;


class Circle 
{
    private:
    // class invariants:
    // m_r > 0
    double m_x; // Data Member
    double m_y;
    double m_r;

    public:
    Circle(double x, double y, double r);
    bool scale(double factor);
    void draw();

};

Circle::Circle(double x, double y, double r) 
{
    m_x = x;
    m_y = y;
    // Testing for the Invariant
    if (m_r <= 0) 
    {
        exit(1);
    }
    else 
    {
        m_r = r;
    }
}

bool Circle::scale(double factor) {
    // Must be strictly positive
    if (m_r <= 0) {
        return false;
    }
    else {
        m_r *= factor;
        return true;
    }
}

double area(Circle x); // not a member function

int main() 
{
    
    Circle c(8, -3, 3.7);
    c.scale(2);
    c.draw();
    cout << area(c) << endl;
}