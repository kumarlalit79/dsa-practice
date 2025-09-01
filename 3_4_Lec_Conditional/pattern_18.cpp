#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    int i = 1;

    while (i <= n) { // for rows
        int j = 1;
        char ch = 'A' + n - i;
        while (j <= i) { // for cols
            cout << ch << " ";
            ch = ch + 1;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
}
