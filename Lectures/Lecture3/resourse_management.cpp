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

String::String