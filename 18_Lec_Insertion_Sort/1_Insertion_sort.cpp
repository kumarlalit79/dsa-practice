#include<iostream>
using namespace std;

void printArray(int arr[] , int size){
    for (int  i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }    
}

void insertionSort(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // to shift kardo
                arr[j+1] = arr[j];
            }
            else{ // ruk jao
                break;
            }
        }
        arr[j+1] = temp;
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
    insertionSort(arr,size);
    printArray(arr , size);
}