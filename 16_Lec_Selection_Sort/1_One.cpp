#include<iostream>
using namespace std;


void printArray(int arr[] , int size){
    for (int  i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
}

void selectionSort(int arr[] , int size){
    for (int i = 0; i < size - 1; i++)
    {
        int minimumIndex = i;
        
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[minimumIndex])
            {
                minimumIndex = j;
            }
        }
        swap(arr[minimumIndex] , arr[i]);        
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
    selectionSort(arr,size);
    printArray(arr , size);

}