#include<iostream>
#include<vector>    
using namespace std;

void printArray(vector<int> &arr , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(vector<int> &arr , int n){
    
    // ye loop round ko darshayega. ham i=1, i<n : ye bhi likh sakte hai
    for (int i = 0; i < n-1; i++)
    {
        
        bool swapped = false;
        
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main(){
        
    vector<int> arr = {64,25,12,22,11};
    bubbleSort(arr , 5);
    printArray(arr,5);
    return 0;
}