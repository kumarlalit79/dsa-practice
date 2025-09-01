#include<iostream>
using namespace std;

int main(){


    int arr[5] = {1,2,3,4,5};
    char ch[5] = "abcd";
    cout << arr << endl; // will print address
    cout << ch << endl; // will print value

    char *c = &ch[0];
    cout << c << endl;
    cout << *c << endl;

    return 0;
}