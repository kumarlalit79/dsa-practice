#include<iostream>
using namespace std;

bool isEven(int n){

    //1 -> Even
    //0 -> odd
    if (n & 1)
    {
        return 0;
    }
    return 1;
}

int main(){

    int n;
    cout << "Enter number : ";
    cin >> n;
    if (isEven(n))
    {
        cout << "Number is even";
    }
    else
        cout << "Number is odd";
}