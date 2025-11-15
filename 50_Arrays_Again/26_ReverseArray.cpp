#include<iostream>
#include<vector>    
using namespace std;

void printArray(vector<int> &arr , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

vector<int> reverseArray(vector<int> &arr){
    int s = 0, e = arr.size()-1;

    while (s<=e)
    {
        swap(arr[s] , arr[e]);
        s++;
        e--;
    }
    return arr;
}

int main(){
        
    vector<int> arr = {64,25,12,22,11};
    vector<int> result = reverseArray(arr);
    printArray(result,5);
    return 0;
}