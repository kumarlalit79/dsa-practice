#include<iostream>
using namespace std;

void swapAlternative(int arr[] , int size){
    for (int i = 0; i < size; i = i + 2)
    {
        if (i+1 < size)
        {
            swap(arr[i] , arr[i+1]);
        }
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

    swapAlternative(arr , size);
    printArray(arr , size);
}