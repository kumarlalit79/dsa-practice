#include <iostream>
using namespace std;

void reverse(string &str, int s) {
    int n = str.length();

    // base case
    if (s >= n - s - 1) {  // jab start >= end ho jaye, stop recursion
        return;
    }

    // swap kar do
    swap(str[s], str[n - s - 1]);

    // recursion call with next index
    reverse(str, s + 1);
}

int main() {
    string str = "abc";
    reverse(str, 0);  // sirf s pass kar rahe hain
    cout << str;
    return 0;
}
