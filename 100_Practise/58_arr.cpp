#include<iostream>
using namespace std;

int getSum(int arr[] , int size){

    int sum = 0;
    for (int i = 0; i < size-1; i++)
    {
        sum += arr[i];
    }
    
    return sum;
}

int main(){

    int arr[100];

    int size;
    cout << "Enter the size of the array  : " << endl;
    cin >> size;

    cout << "Enter the elemets of the array  : " << endl;
    for (int i = 0; i < size-1; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Sum = " << getSum(arr, size);


    return 0;
}