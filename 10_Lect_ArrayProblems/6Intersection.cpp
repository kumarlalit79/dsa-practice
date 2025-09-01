#include<iostream>
using namespace std;


void intersection(int arr1[] , int size1 , int arr2[] , int size2){

    for (int i = 0; i < size1; i++)
    {
        int element = arr1[i];

        for (int j = 0; j < size2; j++) {

            if (element < arr2[j])
            {
                break;
            }
            

            if (element == arr2[j]) {
                cout << element << " ";
                break; 
            }
            
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