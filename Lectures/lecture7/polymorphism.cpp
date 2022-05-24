#include <iostream>

using namespace std;



Class Shape
{
    virtual void move(double xnew, double ynew);
    virtual void draw() const = 0;
    virtual ~Shape();
}

// This is an abstract base class (ABC)

Class Circle : public Shape
{
    virtual void draw() const;
    Circle(double r, double x, double y) : Shape(x, y), m_r(r)

    private:
    int m_r;
}

Shape* pic[100];
pic[0] = new Circle;
pic[1] = new Shape; // compilation error


// If a class is designed to be a base class, declare a destructor for it and make it virtual