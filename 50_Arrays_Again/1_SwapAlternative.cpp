#include<iostream>
using namespace std;

void printArray(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlternative(int arr[] , int size){
    for (int i = 0; i < size; i+=2)
    {
        if (i+1 < size)
        {
            swap(arr[i+1] , arr[i]);
        }
    }
}

int main(){

    int arrEven[6] = {1,3,2,7,11,8};
    int arrOdd[5] = {1,2,8,7,5};

    cout << "Even Swapped" << endl;
    swapAlternative(arrEven , 6);
    printArray(arrEven , 6);

    cout << "Odd Swapped" << endl;
    swapAlternative(arrOdd , 5);
    printArray(arrOdd , 5);

    return 0;
}