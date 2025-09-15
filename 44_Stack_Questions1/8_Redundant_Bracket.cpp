#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Push operators and opening bracket
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            st.push(ch); // agr opening bracket ya operator hai to stack mai push kardo
        }
        else {
            // Closing bracket case
            if (ch == ')') { // age closing bracket hai
                bool isRedundant = true;

                // Jab tak '(' nahi milta tab tak pop karte jao
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    // Agar koi operator mila to iska matlab ye brackets redundant nahi hai
                    if (top == '+' || top == '-' || top == '*' || top == '/' || top == '%') {
                        isRedundant = false;
                    }
                    st.pop(); // last ka opening bracket pop krna padega
                }

                // Yaha par '(' milega, use bhi pop kardo
                if (!st.empty()) st.pop();

                // Agar koi operator nahi mila, iska matlab redundant brackets the
                if (isRedundant) {
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