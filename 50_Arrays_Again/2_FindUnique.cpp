#include<iostream>
using namespace std;

void printArray(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findUnique(int arr[] , int size){
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}


int main(){

    // int arr[5] = {1,3,4,1,3};
    int arr[7] = {2,3,1,6,3,6,2};
    
    cout << "Unique element : " << findUnique(arr , 7);
    

    return 0;
}