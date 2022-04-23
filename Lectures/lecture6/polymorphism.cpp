#include <iostream>
#include <cassert>

using namespace std;

class Shape {
    public:
    void move(double xnew, double ynew);
    virtual void draw const(); // dynamic binding for circle and shape functions
    double m_x
    double m_y;
    
    private:
};

class Circle : public Shape // type  of shape
 {
    private:
    double m_r;
};

class Rectangle : public Shape // type of shape
{
    private:
    double m_dx;
    double m_dy;
};

int main() {
Circle* ca[100]; // array of circle classes
ca[0] = new Circle; // creates a new circle class 
Rectangle* ra[100];
ra[0] = new Rectangle;



// Shape is the base class
// circle & rectangle are derived classes

Shape* pic[100];
pic[0] = new Circle;
pic[1] = new Rectangle;

// this will compile because every single object  of rectangle or 
// circle will have the base class inside of it



return 0;
}
// If we want to change both circles and rectangles, we have to 
// run through both arrays even thoigh they have the same code

// Static Binding vs. Dynamic Binding

// Static Binding will choose function body at compile time
// Dynamic Binding will choose function body at runtime