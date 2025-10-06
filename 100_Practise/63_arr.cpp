#include<iostream>
using namespace std;

int findDuplicateAll(int arr[] , int size){
    int count[100] = {0};
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 0; i < 100; i++)
    {
        if (count[i] == 2)
        {
            cout << i << endl;
        }
        
    }
    
    cout << endl;
}

int main(){

    int arr[8] = {4,3,2,7,8,2,3,1};
    findDuplicateAll(arr,8); 
        
    return 0;
}