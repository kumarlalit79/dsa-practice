#include<iostream>
using namespace std;

// Linear search : batana hai array mai x (x can be any int like 1,2,3,4,20,14,5,15...) present hai ya nahi


bool search(int arr[] , int size , int x){

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

int main(){

    int size;
    cout << "Enter the size of the array : " << endl ; 
    cin >> size;

    int arr[100];

    // taking i/p in array dynamically
    cout << "Enter the " <<size <<" element in array : " << endl ;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int x ;
    cout << "Enter x : " << endl ; 
    cin >> x;

    if (search(arr , size , x))
    {
        cout << "x is present";
    }
    else{
        cout << "x is not present";
    }
}