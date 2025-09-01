#include<iostream>
using namespace std;

void printArray(int arr[] , int size){

    cout << "Printing the array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){

    int size = 5;
    int numbers[5] = {1,2};
    printArray(numbers , size);
}