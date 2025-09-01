#include<iostream>
using namespace std;

int findDuplicate(int arr[] , int size){
    int ans = 0;

    // XOR all elements in the array
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i];
    }

    // XOR with numbers from 1 to size-1
    for (int i = 1; i < size; i++) {
        ans = ans ^ i;
    }

    return ans;
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

    cout << "Duplicate element is : " << findDuplicate(arr , size);
}
