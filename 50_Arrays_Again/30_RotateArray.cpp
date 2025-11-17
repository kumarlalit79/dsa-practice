#include<iostream>
#include<vector>    
using namespace std;

void printArray(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void rotateArray(vector<int> &arr , int k){

    vector<int> temp(arr.size());//rotate krke is temp mai daalenge, original arr mai nahi cuz cheeze overwrite ho jayengi

    for (int i = 0; i < arr.size(); i++)
    {
        temp[(i+k) % arr.size()] = arr[i];
    }
    // jo bhi cheez store krni h wo num waale array mai krni hai,to bas copy kr diya
    arr = temp;
}

int main(){
    
    vector<int> arr = {-1,-100,3,99};
    rotateArray(arr,2);
    printArray(arr);
    
    return 0;
}