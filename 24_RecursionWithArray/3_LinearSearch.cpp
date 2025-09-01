#include<iostream>
using namespace std;

bool linearSearch(int arr[],int size,int key){
    // base case
    if(size == 0){
        return false;
    }
    
    // RR
    if(arr[0] == key){
        return arr[0];
    }else{
        int remainingPart = linearSearch(arr+1, size-1, key);
        return remainingPart;
    }
}

int main(){
    int arr[3] = {1,2,3};
    int key = 5;
    int size = 3;
    bool ans = linearSearch(arr , size,key);
    if(ans){
        cout << "found";
    }
    else{
        cout << "not found";
    }
}