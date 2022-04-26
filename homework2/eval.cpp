// Eval.cpp Apurva Shah 705595011

#include <iostream>
#include <string>
#include <cassert>
#include <stack>
#include <stdio.h>

using namespace std;

int evaluate(string infix, string &postfix, bool &result);
//   If infix is a syntactically valid infix boolean expression,
//   then set postfix to the postfix form of that expression, set
//   result to the value of the expression, and return zero.  If
//   infix is not a syntactically valid expression, return 1; in
//   that case, postfix may or may not be changed, but result must
//   be unchanged.
void removeSpaces(char *infix);
// removes the spaces of the pre-processed infix
bool isValid(string infix);
// checks whether the function is valid
// Must have a closing parenthesis
// Must have value after !
// Must have & in between two characters
// Must have | in between two characters

string removeSpaces(string input)
{
    string temp = "";
    for (int i = 0; i < input.size(); i++)
        if (input[i] != ' ')
            temp += input[i];
    return temp;
}

bool isValid(string input)
{ // returns false if not provided with
    string infix;
    infix = removeSpaces(input);

    // checking whether the string is empty
    if (infix.size() == 0)
    {
        cerr << "Invalid because size 0" << endl;
        return false;
    }

    // Checking Whether the Parenthesis are Empty

    // Preliminary check for number of parenthesis present
    int paren_counter = 0;
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(' || infix[i] == ')')
            paren_counter++;
    }
    if (paren_counter % 2 != 0)
    {
        cerr << "Invalid because mod failed" << endl;
        return false;
    }

    // Check whether the parenthesis are valid
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

    if (paren_stack.empty() == false)
    {
        cerr << "Invalid because something didnt pop" << endl;
        return false;
    }

    // Checking whether there is something within the parenthesis

    stack<int> paren_index;

    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            paren_index.push(i);
            cerr << "Pushed: " << i << endl;
        }
        else
        {
            if (infix[i] == ')')
            {
                if (paren_index.top() + 1 < i)
                {
                    paren_index.pop();
                    continue;
                }
                else
                {
                    cerr << "Invalid because of something in the parenthesis" << endl;
                    return false;
                }
            }
        }
    }

    // Other Operands
    for (int i = 0; i < infix.size(); i++)
    {
        char temp_val = infix[i];
        cerr << "index: " << i << ", value: " << infix[i] << ", next value: " << infix[i + 1] << endl;

        switch (temp_val)
        {
        case 'T':
            if (infix[i + 1] != ')' && infix[i + 1] != '|' && infix[i + 1] != '&' && i != infix.size() - 1)
            {
                cerr << "Failed at the T operand" << endl;
                return false;
            }
            break;
        case 'F':
            if (infix[i + 1] != ')' && infix[i + 1] != '|' && infix[i + 1] != '&' && i != infix.size() - 1)
            {
                cerr << "Failed at the F operand" << endl;
                return false;
            }
            break;
        case '&':
            if (infix[i + 1] != 'T' && infix[i + 1] != 'F' && infix[i + 1] != '(' && infix[i + 1] != '!')
            {
                cerr << "Failed at the & operator" << endl;
                return false;
            }
            if (infix[i - 1] != 'T' && infix[i - 1] != 'F' && infix[i - 1] != ')')
            {
                cerr << "Failed at the & operator" << endl;
                return false;
            }
            break;
        case '!':
            break;
        case '|':
            if (infix[i + 1] != 'T' && infix[i + 1] != 'F' && infix[i + 1] != '(' && infix[i+1] != '!')
            {
                cerr << "Failed at the | operator" << endl;
                return false;
            }
            if (infix[i - 1] != 'T' && infix[i - 1] != 'F' && infix[i - 1] != ')')
            {
                cerr << "Failed at the | operator" << endl;
                return false;
            }
            break;
        case '(':
            break;
        case ')':
            break;
        default:
            return false;
        }
    }

    return true;

} // end isValid

int evaluate(string infix, string &postfix, bool &result)
{

    return 0;
}

int main()
{
    // T                          evaluates to true
    //     (F)                        evaluates to false
    //     T&(F)                      evaluates to false
    //     T & !F                     evaluates to true
    //     !(F|T)                     evaluates to false
    //     !F|T                       evaluates to true
    //     T|F&F                      evaluates to true
    //     T&!(F|T&T|F)|!!!(F&T&F)    evaluates to true

    string s = "F F";
    if (isValid(s) == true)
    {
        cout << "This is valid" << endl;
    }
    else
    {
        cout << "Invalid operand" << endl;
    }
    return 0;
}