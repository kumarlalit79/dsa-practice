#include<iostream>
using namespace std;

int findUnique(int arr[] , int size){
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
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

    cout << "Unique Number : " << findUnique(arr , size);
}