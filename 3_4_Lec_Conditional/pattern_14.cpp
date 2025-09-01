#include<iostream>
using namespace std;

int main(){

    int n ;
    cout << "Enter n : ";
    cin >> n;

    int i = 1; 
    
    while (i <= n) // for row
    {
        int j = 1;
        while(j <= n){ // for col
            char ch = 'A' + i + j - 2;
            cout << ch;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
}