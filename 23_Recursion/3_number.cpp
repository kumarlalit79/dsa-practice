#include<iostream>
using namespace std;

void number(int n){

    // base case
    if(n == 0)
        return ;
    // processing
    cout << n << endl;
    // recursive
    number(n-1);
    
}

int main(){

    int n;
    cout << "enter number :" << endl;
    cin >> n; 
    number(n);
}