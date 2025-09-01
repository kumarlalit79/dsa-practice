#include<iostream>
using namespace std;

int getSum(int arr[], int size){
    // base case
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }

    // RR
    int remainingPart = getSum(arr+1, size-1);
    int ans = arr[0] + remainingPart;
    return ans;
}

int main(){
    int arr[3] = {2,4,6};
    int size = 3;
    int ans = getSum(arr , size);
    cout << "sum is : " << ans;
}