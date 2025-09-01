#include<iostream>
using namespace std;

void printArray(int arr[] , int size){
    for (int  i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }    
}

void bubbleSort(int arr[] , int size){
    for (int i = 0; i < size-1; i++) // it is indicating rounds.
    {
        for (int j = 0; j < size - i; j++)//kyuki j hamesha starting se check or compare karega.
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];

    cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << "Sorted array : " ;
    bubbleSort(arr,size);
    printArray(arr , size);
}