#include<iostream>
using namespace std;


int binarySearch(int arr[] ,int size , int key){
    int i = 0, j = size - 1;
    int mid = (i + j) / 2;
    while (i <= j)
    {
        if (arr[mid] == key)
        {
            return mid; //returning index
        }
        // go to right part
        if(key > arr[mid]){
            i = mid + 1;
        }
        else{ // key < arr[mid]
            j = mid - 1; // go left
        }
        // calculating new mid
        mid = (i + j) / 2;
    }
    return -1;
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

    int key;
    cout << "Enter the key : ";
    cin >> key;

    cout << binarySearch(arr , size , key);

}