#include<iostream>
using namespace std;


void printArray(int arr[] , int size){
    for (int  i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
}

void sortZeronetwo(int arr[], int size){
    int i = 0;         // for 0s
    int j = 0;         // current element
    int k = size - 1;  // for 2s

    while (j <= k) {
        while (arr[j] == 0 && j <= k) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }

        while (arr[j] == 2 && j <= k) {
            swap(arr[j], arr[k]);
            k--;
        }

        while (arr[j] == 1 && j <= k) {
            j++;
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

    sortZeronetwo(arr , size);
    printArray(arr , size);

}