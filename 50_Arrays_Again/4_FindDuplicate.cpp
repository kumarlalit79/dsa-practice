#include<iostream>
using namespace std;

int findDuplicate(int arr[] , int size){
    int ans = 0;

    // XOR with all array elements
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR with [1 , N-1]
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ i;
    }
    return ans;
    
}

int main(){

    int arr[5] = {1,2,3,4,3};
    int size = 5;
    cout << findDuplicate(arr , size);
    return 0;
}