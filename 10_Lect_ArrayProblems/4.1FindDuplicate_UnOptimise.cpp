#include<iostream>
using namespace std;

int findDuplicate(int arr[] , int size){
    int count[100] = {0};
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;

        if (count[arr[i]] > 1)
        {
            return arr[i];
        }
        
    }
    return -1;
}

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];

    cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << "Duplicate element is : " << findDuplicate(arr , size);
}
