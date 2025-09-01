#include<iostream>
using namespace std;

int sumOfElement(int arr[] , int size){

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    
    return sum;
}

int main(){
    
    int size;
    cout << "Enter the size of the array : " << endl ; 
    cin >> size;

    int num[100];

    // taking i/p in array dynamically
    cout << "Enter the " <<size <<" element in array : " << endl ;
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    cout << "Sum = " << sumOfElement(num , 5);

}