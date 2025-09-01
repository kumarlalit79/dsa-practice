#include<iostream>
using namespace std;

int main(){

    int n ;
    cout << "Enter n : ";
    cin >> n;

    int i = 1; 
    char value = 'A' ;

    while (i <= n) // for row
    {
        int j = 1;
        while(j <= i){ // for col
            cout << value;
            value = value + 1;
            j = j + 1;
        } 
        cout << endl;
        i = i + 1;
    }
}