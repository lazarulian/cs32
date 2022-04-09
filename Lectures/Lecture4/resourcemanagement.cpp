#include <iostream>

using namespace std;

void h() {
    String s("Hello");
}

class String
{
    public:
        String(const char* value);
        String();
        String(const String& other);
        String& operator = (const string& rhs);
        ~String(); // Destructor
    private:
    // Class Invariants
    // m_text ios a pointer to a dynamically allocated array of a m_len+1 characters
    // m_len >0
    // m_len == strlen(m_text)
        char m_text[100000]; //every string will take up 100,000 bytes
        char* m_text; // dynamically allocated array of characters
        // Issue of this is you have to keep the memory in check when you are
        // dynamically allocating
        int m_len;
};

String::String() {

}

void f(String t)
{
    ....
}

void h()
{
    String s("Hello");
    f(s); // copy constructor
    String u ("wow");
    u = s; // assignment already has value so different constructor needed
    // solution
    u.operator(s);
    // replace length of the char array
    // delete the contents of the array
    // point u to the new array through dynamic allocation
}



String::String(const String& other) { // we dont change it so its const
    m_len = other.m_len; // set own mlen to other mlen
    m_text = new char[m_len + 1]; // dynamically allocate array of whatever characters and copy it with 0 byte
    strcpy(m_text, other.m_text); // copies m_text from the other
}

String& String::operator = (const string& rhs) {
    if (this != &rhs) {
        delete [] m_text; // cleans lhs
        m_len = rhs.m_len; // set own mlen to other mlen
        m_text = new char[m_len + 1]; // dynamically allocate array of whatever characters and copy it with 0 byte
        strcpy(m_text, rhs.m_text); // copies m_text from the other
    }
    return *this;
}