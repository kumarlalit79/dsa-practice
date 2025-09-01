#include<iostream>
using namespace std;

bool binarySearch(int arr[],int s, int e,int key){
    // base case 1 - when element not found
    if(s>e){
        return false;
    }

    int mid = s + (e-s) / 2;
    
    // base case 2 - when element found
    if(arr[mid] == key){
        return true;
    }
    
    // RR
    if(arr[mid] < key){
        //search in right half
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        //search in left half
        return binarySearch(arr,s,mid-1,key);
    }
    
}

int main(){
    int arr[3] = {1,2,3};
    int key = 5;
    int s = 0;
    int e = 2;
    bool ans = binarySearch(arr,s,e,key);
    if(ans){
        cout << "found";
    }
    else{
        cout << "not found";
    }
}