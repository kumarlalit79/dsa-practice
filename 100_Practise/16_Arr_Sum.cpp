#include<iostream>
using namespace std;

int arrSum(int arr[] , int size){

    if (size == 0)
    {
        return 0;
    }
    
    if (size == 1)
    {
        return arr[0];
    }

    int remainingPart = arrSum(arr+1 , size-1);
    int ans = arr[0] + remainingPart;
    return ans;
}

int main(){

    int arr[5] = {3,2,5,1,6};
    
    cout << arrSum(arr , 5);

    return 0;
}