#include<iostream>
using namespace std;

void tripletSum(int arr[] , int size , int x){

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            for (int k = j+1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    break;
                }
            }
        }
    }
}

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];
    
    int x;
    cout << "Enter x : ";
    cin >> x;

    cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << "Pairs are : " << endl;
    tripletSum(arr , size , x);
}