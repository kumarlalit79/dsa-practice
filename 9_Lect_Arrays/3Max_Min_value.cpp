#include<iostream>
#include <climits>
using namespace std;

int getMin(int num[] , int n){
    int min = INT_MAX; // default case mai maximum value padi hai

    for (int i = 0; i < n; i++)
    {
        if (num[i] < min)
        {
            min = num[i];
        }
    }
    return min;
}

int getMax(int num[] , int n){
    int max = INT_MIN; // default case mai minimum value padi hai

    for (int i = 0; i < n; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
    }
    return max;
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

    cout << "Maximum value is : " << getMax(num , size) << endl;
    cout << "Minimum value is : " << getMin(num , size) << endl;
}