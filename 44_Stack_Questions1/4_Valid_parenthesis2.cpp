#include<iostream>
#include<stack>
using namespace std;

bool isParenthesis(string expression, int &openCount, int &closeCount, int &pairCount) {
    stack<char> s;
    openCount = closeCount = pairCount = 0;

    for (char ch : expression) {
        if (ch == '(') {
            openCount++;
            s.push(ch);
        }
        else if (ch == ')') {
            closeCount++;
            if (!s.empty() && s.top() == '(') {
                s.pop();
                pairCount++;
            }
            else {
                return false; // unbalanced closing bracket
            }
        }
    }

    return s.empty(); // balanced tabhi hoga jab stack empty ho
}

int main() {
    string expr = "((())()()()())";

    int openCount, closeCount, pairCount;
    bool balanced = isParenthesis(expr, openCount, closeCount, pairCount);

    cout << "Expression: " << expr << endl;
    cout << "Total Opening Brackets: " << openCount << endl;
    cout << "Total Closing Brackets: " << closeCount << endl;
    cout << "Total Valid Pairs: " << pairCount << endl;
    cout << "Is Balanced: " << (balanced ? "YES" : "NO") << endl;

    return 0;
}
