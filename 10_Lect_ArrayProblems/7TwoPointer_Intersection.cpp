#include<iostream>
using namespace std;


void intersection(int arr1[] , int size1 , int arr2[] , int size2){

    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}

int main(){

    // Array 1
    int size1;
    cout << "Enter the size of the first array: ";
    cin >> size1;

    int arr1[100];

    cout << "Enter " << size1 << " elements in the array: ";
    for (int i = 0; i < size1; i++){
        cin >> arr1[i];
    }

    // Array 2
    int size2;
    cout << "Enter the size of the second array: ";
    cin >> size2;

    int arr2[100];

    cout << "Enter " << size2 << " elements in the array: ";
    for (int i = 0; i < size2; i++){
        cin >> arr2[i];
    }

    cout << "Intersection : ";
    intersection(arr1, size1, arr2, size2);
}