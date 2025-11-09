#include<iostream>
using namespace std;

void printArray(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOne(int arr[] , int size){
    
    int i = 0 , j = size-1;
    while (i < j)
    {
        while (arr[i] == 0 && i < j)
        {
            i++;
        }
        while (arr[j] == 1 && i < j)
        {
            j--;
        }
        // agar yaha tk pahuch chuke ho to iska mtlb arr[i]==1 hoga and arr[j]==0 hoga. is conditon mai swap krna hota hai
        swap(arr[i] , arr[j]); 
        i++;
        j--;
    }
}

int main(){

    int arr[8] = {1,0,1,0,1,1,0,0};
    sortOne(arr , 8);
    printArray(arr , 8);
    return 0;
}