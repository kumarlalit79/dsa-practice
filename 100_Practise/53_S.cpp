#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s){

    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else{
            if (ch == ')')
            {
                bool isReduandant = true;
                while (!st.empty() && st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isReduandant = false;
                    }
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
                if (isReduandant)
                {
                    return true;
                }
                
            }
            
        }
    }
    return false;

}

int main() {
    string s;
    cout << "Enter expression: ";
    cin >> s;

    if (findRedundantBrackets(s)) {
        cout << "Redundant brackets found!" << endl;
    }
    else {
        cout << "No redundant brackets." << endl;
    }

    return 0;
}

/*
    test case 1 : ((a+b))
    test case 2 : (a+(b*c))
*/