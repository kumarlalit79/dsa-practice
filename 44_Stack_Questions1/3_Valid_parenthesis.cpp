#include<iostream>
#include<stack>
using namespace std;


bool isParenthesis(string expression){

    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i]; // ek character mil gaya, wo openinig bracket bhi ho skta or closing bhi

        // if opening bracket, stack mai push kardo
        // if closing bracket, stack top check karlo and pop kardo

        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else{
            // mtlb closing bracket hai
            if (!s.empty()) // stack empty na ho check karre
            {
                char top = s.top(); // stack ka top element nikaal liya

                // top element ko closing bracket se match karna hota hai
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')) 
                {
                    s.pop(); // agr match kar jate hai to pop kardo
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else{
        return false;
    }
}


int main() {
    string expr;

    cout << "Enter an expression: ";
    cin >> expr;

    if (isParenthesis(expr)) {
        cout << "Balanced Parenthesis " << endl;
    }
    else {
        cout << "Not Balanced " << endl;
    }

    return 0;
}

/*
    {[()]}
    {(]}
*/