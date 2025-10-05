#include<iostream>
using namespace std;

void reverseArr(int arr[] , int size){

    int i = 0;
    int j = size-1;
    while (i < j)
    {
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
    
}

void print(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){

    int arr[100];

    int size;
    cout << "Enter the size of the array  : " << endl;
    cin >> size;
 
    cout << "Enter the elemets of the array  : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i] ;
    }
    
    cout << "Original array  : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }

    reverseArr(arr , size);
    cout << "Reversed array  : " << endl;
    print(arr , size);

    
    
    
    
    return 0;
}