#include<iostream>
using namespace std;


void printArray(int arr[] , int size){
    for (int  i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
}

// more better then below one
void sortZerone(int arr[] , int size){

    int i = 0 , j = size-1;

    while (i < j)
    {
        while (arr[i] == 0 && i < j)
        {
            i++;
        }
        while (arr[j] == 1 && i < j)
        {
            j--;
        }
        
        if (i < j)
        {
            swap(arr[i] , arr[j]);
            i++;
            j--;
        }
    }
}


// void sortZerone(int arr[], int size) {
//     int left = 0;
//     int right = size - 1;

//     while (left < right) {
//         if (arr[left] == 0) {
//             left++;
//         }
//         else if (arr[right] == 1) {
//             right--;
//         }
//         else {
//             swap(arr[left], arr[right]);
//             left++;
//             right--;
//         }
//     }
// }

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];

    cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    sortZerone(arr , size);
    printArray(arr , size);

}