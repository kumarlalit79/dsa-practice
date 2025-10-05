#include<iostream>
using namespace std;


void swappAlternative(int arr[] , int size){

    int i = 0;
    int j = i + 1;

    while (i < size -1)
    {
        swap(arr[i] , arr[j]);
        i = i+2;
        j = j+2;
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
        cout << arr[i] << " ";
    }

    swappAlternative(arr , size);
    cout << "Swapped array  : " << endl;
    print(arr , size);

    return 0;
}