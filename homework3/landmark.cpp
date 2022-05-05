// landmark.cpp Apurva Shah 705595011
// exploring inheritance and polymorphisms within c++

// basic declarations

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// Base Class Declaration

class Landmark
{
public:
    Landmark(string name) : m_name(name) {}
    string name() const
    {
        return m_name;
    }
    virtual ~Landmark() {}
    virtual string color() const { return NULL; }
    virtual string icon() const { return NULL; }

private:
    string m_name;
};

class Restaurant : public Landmark
{
public:
    Restaurant(string name, int seating_cap) : Landmark(name), m_seatingcap(seating_cap)
    { // setting the dynamic icon
        if (seating_cap < 40)
        {
            real_icon = "small knife/fork";
        }
        else
        {
            real_icon = "large knife/fork";
        }
    }
    virtual ~Restaurant() { cout << "Destroying the restaurant " << name() << "." << endl; }

    virtual string icon() const { return real_icon; }
    virtual string color() const { return "yellow"; }

private:
    string real_icon;
    int m_seatingcap;
};

class Hospital : public Landmark
{
public:
    Hospital(string name) : Landmark(name)
    {
    }
    virtual ~Hospital() { cout << "Destroying the hospital " << name() << "." << endl; }
    virtual string icon() const { return "H"; }
    virtual string color() const { return "blue"; }
};

class Hotel : public Landmark
{
public:
    Hotel(string name) : Landmark(name)
    {
    }
    virtual ~Hotel() { cout << "Destroying the hotel " << name() << "." << endl; }
    virtual string icon() const { return "bed"; }
    virtual string color() const { return "yellow"; }
};