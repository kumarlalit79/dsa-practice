#include<iostream>
using namespace std;

int main(){

    int arr[3] = {10,20,30};

    // way 1 of printing
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;

    // way 2 of printing
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << endl;   
    }
}