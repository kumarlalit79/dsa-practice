#include<iostream>
using namespace std;

int main(){

    int arr[10];
    cout << arr << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;
    cout << &arr[1] << endl;
    cout << &arr[2] << endl;

    cout << *arr << endl;

    int arr2[5] = {10,20,30,40};
    cout <<"Arr2 : " <<  arr2 << endl; // prints address
    cout <<"Arr2 : " <<  *arr2 << endl; // pirnts value
    cout <<"Arr2 : " <<  *arr2 + 1 << endl; // 11 pirnt  
    cout <<"Arr2 : " <<  *(arr2 + 1) << endl; // 1st location value pirnt  
    cout <<"Arr2 : " <<  *(arr2 + 2) << endl; // 2nd location value pirnt  
    cout <<"Arr2 : " <<  *(arr2) + 1 << endl; // value at 0th loc + 1 = 10+1=11
    return 0;
}