#include<iostream>
using namespace std;

// Swap function to swap two elements by reference
void swapArr(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Swap alternate elements in the array
void swapAlternative(int arr[], int size){
    for (int i = 0; i < size; i = i + 2){
        if (i + 1 < size){
            swapArr(arr[i], arr[i + 1]);
        }
    }
}

// Print the array
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
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

    swapAlternative(arr, size);

    cout << "Array after swapping alternate elements: ";
    printArray(arr, size);

    return 0;
}
