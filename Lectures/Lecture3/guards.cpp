#include <iostream>

using namespace std;

// point.H
// ========

#ifndef POINT_INCLUDED // if it is not defined, then define this
#define POINT_INCLUDED

class Point {

};

#endif // POINT_INCUDED


// circle.H
// ========
#include point.H
class Circle {
    private: 
    point p(2, 4);
}

// myapp.cpp
// ========

#include circle.H

int main() {

    Circle c(-2, 5, 10);
    Point p(2, 4);

    return 0;
}