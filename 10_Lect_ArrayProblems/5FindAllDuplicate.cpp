#include<iostream>
using namespace std;

void findAllDuplicate(int arr[] , int size){

    int count[101] = {0};  // initialize all to 0
    
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    
    cout << "Duplicate elements are: ";
    for (int i = 1; i <= size; i++) {
        if (count[i] == 2) {
            cout << i << " ";
        }
    }

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

    findAllDuplicate(arr , size);
}