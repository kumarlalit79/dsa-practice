#include<iostream>
#include<vector>    
using namespace std;

void printArray(vector<int> &arr , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

vector<int> reverseArray(vector<int> &arr , int m){
    int s = m+1, e = arr.size()-1;

    while (s<=e)
    {
        swap(arr[s] , arr[e]);
        s++;
        e--;
    }
    return arr;
}

int main(){
        
    vector<int> arr = {1,2,3,4,5,6};
    vector<int> result = reverseArray(arr,3);
    printArray(result,6);
    return 0;
}