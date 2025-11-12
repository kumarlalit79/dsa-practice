#include<iostream>
using namespace std;

int getPivotElement(int arr[] , int size){

    int start = 0;
    int end = size - 1;

    int mid = start + (end-start) / 2;

    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end-start) / 2;
    }
    return start;
}

int binarySearch(int arr[] , int s , int e , int key){

    int start = s;
    int end = e;

    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if(arr[mid] == key){
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;    
}

int findPosition(int arr[] , int size , int k){

    int pivot = getPivotElement(arr ,size);
    if (k >= arr[pivot] && k <= arr[size-1])
    {
        // second line mai BS laga do
        return binarySearch(arr , pivot , size-1 , k);
    }
    else{
        // first line mai BS laga do
        return binarySearch(arr , 0 ,pivot ,k);
    }
}

int main(){

    int arr[5] = {8,10,17,1,3};
    cout << "Element's index is : " << findPosition(arr , 5 , 1);
        
    return 0;
}