#include <iostream>

using namespace std;



// course.H

#ifndef COURSE_H
#define COURSE_H

class Student;

class Course {

    int units const();

    Student* m_roster[1000];

};

#endif COURSE_H


//myapp.cpp

#include course.H 
#include student.H // must have this because it needs to implement the student class

void f(Student* s, Course* cp) {
    s->enroll(cp);
}