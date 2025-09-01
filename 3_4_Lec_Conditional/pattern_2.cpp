#include<iostream>
using namespace std;

int main(){

    int n ;
    cout << "Enter n : ";
    cin >> n;

    int i = 1; // for row

    while (i <= n)
    {
        int j = 1; // for col
        while(j <= n){
            cout << i;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
}