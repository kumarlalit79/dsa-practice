#include<iostream>
#include<climits>
using namespace std;

int minimumValue(int arr[] , int size){

    int min = INT_MAX;
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;

}

int maximumValue(int arr[] , int size){
    int max = INT_MIN;
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
    }
    return max;
}

int main(){

    int arr[100];   
    int size;
    cout << "Enter the size of the array " << endl;
    cin >> size;
    cout << "Enter the elements in array " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Minimum element : " << minimumValue(arr , size);
    return 0;
}