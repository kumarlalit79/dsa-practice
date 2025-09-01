#include<iostream>
using namespace std;

int getPivot(int arr[] , int size){

    int i = 0 , j = size-1;
    int mid = i + (j - i) / 2;

    while (i < j)
    {
        if (arr[mid] >= arr[0])
        {
            i = mid + 1;
        }
        else{
            j = mid;
        }
        mid = i + (j - i) / 2;
    }
    return i;    
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

    cout << "Pivot element index : " << getPivot(arr , size);
}