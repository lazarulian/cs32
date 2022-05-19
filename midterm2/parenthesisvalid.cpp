#include <iostream>
#include <stack>
#include <cassert>
#include <string>

using namespace std;

bool isValid(string infix)
{
    stack<char> paren_stack;

    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
            paren_stack.push(infix[i]);
        else
        {
            if (infix[i] == ')' && paren_stack.empty() == true)
            {
                cerr << "Invalid closing before opening" << endl;
                return false;
            }
            if (paren_stack.empty() != true)
            {
                char top_stack = paren_stack.top();
                if (infix[i] == ')' && top_stack == '(' && paren_stack.empty() != true)
                {
                    paren_stack.pop();
                    continue;
                }
            } // end if
            else
            {
                continue;
            }
        } // end else
    }     // end for loop
}

int main()
{
    return 0;
}