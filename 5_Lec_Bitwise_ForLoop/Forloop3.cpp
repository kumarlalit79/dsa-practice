#include<iostream>
using namespace std;

int main(){

    // Fibonacci series
    int n ;
    cout << "Enter n : ";
    cin >> n;

    // a and b always fix rahenge.
    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";

    for(int i = 1; i <= n; i++){
        int next_num = a + b;
        cout << next_num << " ";

        a = b;
        b = next_num;
    }
}