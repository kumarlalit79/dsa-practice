#include<iostream>
using namespace std;

bool sorting(int arr[], int size){
    // base case
    if(size == 0 || size == 1){
        return true;
    }
    // RR
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool remainingPart = sorting(arr+1 , size-1);
        return remainingPart;
    }
}

int main(){
    int arr[6] = {2,4,6,9,11,13};
    int size = 6;
    int ans = sorting(arr , size);
    if(ans){
        cout << "array is sorted";
    }
    else{
        cout << "array is not sorted";
    }
}