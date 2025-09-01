#include<iostream>
using namespace std;

void reverseArr(int arr[] , int size){
    
    for (int i = 0 ,  j = size-1; i <= j; i++ , j--)
    {
        swap(arr[i] , arr[j]);
    }
    
}

void printArray(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main(){

    int size;
    cout << "Enter the size of the array : " << endl ; 
    cin >> size;

    int arr[100];

    // taking i/p in array dynamically
    cout << "Enter the " <<size <<" element in array : " << endl ;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    reverseArr(arr , size);

    printArray(arr , size);
}