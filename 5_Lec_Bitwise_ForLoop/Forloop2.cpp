#include<iostream>
using namespace std;

int main(){

    // 1 to n sum of all number
    int n ;
    cout << "Enter n : ";
    cin >> n;

    int temp = 0;

    for(int i = 1; i <= n; i++){
        temp = temp + i;
    }
    cout << temp << endl;
}