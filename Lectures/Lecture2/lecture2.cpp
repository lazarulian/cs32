#include <iostream>
#include <cstdlib>
#include <cmath>

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
    // Accessors
    double radius() const;
    void draw() const;
    // Constructor 
    Circle(double x, double y, double r);
    // Mutator
    bool scale(double factor);

};

Circle::Circle(double x, double y, double r) : m_x(x), m_y(y), m_r(r)
{
    // Testing for the Invariant
    if (m_r <= 0) 
    {
        exit(1);
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

double Circle::radius() const{
    return m_r;
}

void Circle::draw() {
    // random package that will draw the circle
}

double area(const Circle& x) {
    const double pi = 4*atan(1.0);
    return pi*x.radius()*x.radius();
} // not a member function

int main() 
{
    
    Circle c(8, -3, 3.7);
    cout << c.scale(2); // testing to see if it fails
    c.scale(2);
    c.draw();
    cout << area(c) << endl;
    double z;
    cin >> z;
    

}