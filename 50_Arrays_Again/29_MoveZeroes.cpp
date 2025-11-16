#include<iostream>
#include<vector>    
using namespace std;

void printArray(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void moveZeroes(vector<int> &arr){
    int i = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[j] , arr[i]);
            i++;
        }
            
    }
    
}

int main(){
    
    vector<int> arr = {0,1,0,3,12,0};
    moveZeroes(arr);
    printArray(arr);
    
    return 0;
}