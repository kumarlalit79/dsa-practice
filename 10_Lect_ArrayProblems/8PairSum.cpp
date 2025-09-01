#include<iostream>
using namespace std;

void pairSum(int arr[] , int size , int x){

    
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == x)
            {
                // sorting
                if (arr[i] < arr[j])
                {
                    cout << arr[i] << " " << arr[j] << endl;
                }
                else{
                    cout << arr[j] << " " << arr[i] << endl;
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
    pairSum(arr , size , x);
}