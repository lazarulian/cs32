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
    ~Restaurant() { cout << "Destroying the restaurant " << name() << "." << endl; }

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
    ~Hospital() { cout << "Destroying the hospital " << name() << "." << endl; }
    virtual string icon() const { return "H"; }
    virtual string color() const { return "blue"; }
};

class Hotel : public Landmark
{
public:
    Hotel(string name) : Landmark(name)
    {
    }
    ~Hotel() { cout << "Destroying the hotel " << name() << "." << endl; }
    virtual string icon() const { return "bed"; }
    virtual string color() const { return "yellow"; }
};

void display(const Landmark *lm)
{
    cout << "Display a " << lm->color() << " " << lm->icon() << " icon for "
         << lm->name() << "." << endl;
}

int main()
{
    new Landmark("La Picadura del Oso");
    Landmark *landmarks[4];
    landmarks[0] = new Hotel("Westwood Rest Good");
    // Restaurants have a name and seating capacity.  Restaurants with a
    // capacity under 40 have a small knife/fork icon; those with a capacity
    // 40 or over have a large knife/fork icon.
    landmarks[1] = new Restaurant("Bruin Bite", 30);
    landmarks[2] = new Restaurant("La Morsure de l'Ours", 100);
    landmarks[3] = new Hospital("UCLA Medical Center");

    cout << "Here are the landmarks." << endl;
    for (int k = 0; k < 4; k++)
        display(landmarks[k]);

    // Clean up the landmarks before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete landmarks[k];
}

// Here are the landmarks.
// Display a yellow bed icon for Westwood Rest Good.
// Display a yellow small knife/fork icon for Bruin Bite.
// Display a yellow large knife/fork icon for La Morsure de l'Ours.
// Display a blue H icon for UCLA Medical Center.
// Cleaning up.
// Destroying the hotel Westwood Rest Good.
// Destroying the restaurant Bruin Bite.
// Destroying the restaurant La Morsure de l'Ours.
// Destroying the hospital UCLA Medical Center.