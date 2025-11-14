#include<iostream>
#include<vector>    
using namespace std;

void printArray(vector<int> &arr , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
}

void selectionSort(vector<int> &arr , int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i; // jaha pe aap currently khade ho wo hi min ka index maan liya. like i=0 pe khade h
        
        // i=0 pe suppose ham hai, to mai baaki bache hue array mai check karunga ki koi chhota to nahi hai. isliye j ko i+1 se chalaya
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex] , arr[i]);
    }
}

int main(){
        
    vector<int> arr = {64,25,12,22,11};
    selectionSort(arr , 5);
    printArray(arr,5);
    return 0;
}