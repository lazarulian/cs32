// sample.cpp Apurva Shah 705595011

#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

/////////////////////////////////////////
////// Forward Declaration
/////////////////////////////////////////
int evaluate(string infix, string &postfix, bool &result);
string removeSpaces(string input);
bool isValid(string input);
int getPresedence(char opp);
string prefixToPost(string infix);
bool charToBool(char value);
char boolToChar(bool value);
bool evaluatePostFix(string postfix);

/////////////////////////////////////////
////// Implementations
/////////////////////////////////////////

// charToBool
bool charToBool(char value) 
{ // converts character types into boolean expressions
    if (value == 'T') {
        return true;
    }
    else {
        return false;
    }
}

// boolToChar
char boolToChar(bool value) 
{ // converts bools to char values
    if (value == true) {
        return 'T';
    }
    else {
        return 'F';
    }
}

// removeSpaces
string removeSpaces(string input)
{ // removes spaces from a string
    string temp = "";
    for (int i = 0; i < input.size(); i++)
        if (input[i] != ' ')
            temp += input[i];
    return temp;
}

// getPresedence
int getPresedence(char opp)
{ // establishes the presedence of the functions
    switch (opp)
    {
    case '!':
        return 4;
    case '&':
        return 3;
    case '|':
        return 2;
    case '(':
        return 1;
    default:
        return -1;
    }
}

// isValid
bool isValid(string input)
{ // returns false if not provided with the correct value
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
            if (i == infix.size()-1)
                return false;
            break;
        case '|':
            if (infix[i + 1] != 'T' && infix[i + 1] != 'F' && infix[i + 1] != '(' && infix[i + 1] != '!')
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



// prefixToPost
string prefixToPost(string infix)
{ // converts prefix values to postfix
    string postfix = "";
    stack<char> opstack;

    // Iterate through the stack
    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];
        switch (ch)
        {
        case 'T':
            postfix += infix[i];
            break;
        case 'F':
            postfix += infix[i];
            break;
        case '(':
            opstack.push(ch);
            break;
        case ')':
            while (opstack.empty() != true && opstack.top() != '(')
            {
                postfix += opstack.top();
                opstack.pop();
            }
            if (!opstack.empty()) {
                opstack.pop();
            }
            break;
        case '&':
            while (opstack.empty() != true && opstack.top() != '(' && getPresedence(infix[i]) <= getPresedence(opstack.top()))
            {
                postfix += opstack.top();
                opstack.pop();
            }
            opstack.push(infix[i]);
            break;
        case '|':
            while (opstack.empty() != true && opstack.top() != '(' && getPresedence(infix[i]) <= getPresedence(opstack.top()))
            {
                postfix += opstack.top();
                opstack.pop();
            }
            opstack.push(infix[i]);
            break;
        case '!':
            opstack.push(infix[i]);
            break;
        } // end switch
    }     // end for loop
    while (!opstack.empty())
    {
        postfix += opstack.top();
        opstack.pop();
    } // end conversion
    return postfix;
} // end function

// evaluatePostFix
bool evaluatePostFix(string postfix) 
{ // evaluates the postfix expression and returns a boollean 
    stack <char> opstack;
    bool optop1;
    bool optop2;
    for (int i = 0; i < postfix.size(); i++)
    {
        // Operands
        char ch = postfix[i];
        if (ch == 'T' || ch == 'F') {
            opstack.push(ch);
            continue;
        }
        // Exclamation Points
        else if (ch == '!') {
            if (!opstack.empty())
            {
                optop1 = charToBool(opstack.top());
                opstack.pop();
                opstack.push(boolToChar(!optop1));
                continue;
            }
        }
        else 
        {
            if (ch == '&' && opstack.size() >= 2) 
            {
                optop1 = charToBool(opstack.top());
                opstack.pop();
                optop2 = charToBool(opstack.top());
                opstack.pop();
                opstack.push(boolToChar(optop2&optop1));
                continue;
            }
            if (ch == '|' && opstack.size() >= 2) 
            {
                optop1 = charToBool(opstack.top());
                cerr << "optop1 is: " << optop1 << endl;
                opstack.pop();
                optop2 = charToBool(opstack.top());
                cerr << "optop2 is: " << optop2 << endl;
                opstack.pop();
                opstack.push(boolToChar(optop2|optop1));
                continue;
            }
            continue;
        }
    } // end for loop
    if (opstack.size() == 1)
        return charToBool(opstack.top());
    else {
        cerr << "you fucked up bigtime somewhere" << endl;
        return false;
    }
} // end function

// evaluate
int evaluate(string infix, string &postfix, bool &result)
{ // compiles how professor wants it
    if (isValid(infix) == false) {
        cerr << "It is not valid" << endl;
        return 1;
    }
    else {
        postfix = prefixToPost(infix);
        result = evaluatePostFix(postfix);
        return 0;
    }
}

int main()
{
	string cases[57] = {
		"", "()", "(())", ")(", "))((", 
		"(T", "T)", "((T|F)", "(T|F))",
		")T(", ")F(", "))T((", "))F((",
		"TT", "TF", "FT", "FF", "TTT", "TTF", "TFT", "FTT", "TFF", "FFT", "FTF", "FFF",
		"T&&T", "T&|F", "T|&F", "T!&F", "T!|F", "T!!F",
		"&", "&T", "&F", "|", "|T", "|F", "T&", "F&", "T|", "F|",
		"(&T&T)", "(|T&T)", "(T&T!)", "(T&T&)", "(T&T|)", "(T&T)!",
		"(&T)", "(&F)", "(|T)", "(|F)",
		"T!T", "T!F", "F!T", "F!F",
		"T!", "F!"
	};
	string postfix = "";
	bool result = false;
    for (int i = 0; i < 57; i++)
	{
		cout << "Case: " << cases[i] << endl;
		assert(evaluate(cases[i], postfix, result) == 1);
		assert(result == false);
	}
}