#include<iostream>
using namespace std;


int aggressiveCow(int Stall , int k) {

    int i = 0;
    int maxi = -1;
    for (int i = 0; i < Stall; i++)
    {
                    
    }
    

}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];
    cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int Stall;
    cout << "Enter Stall : ";
    cin >> Stall;

    int K;
    cout << "Enter K : ";
    cin >> K;

    cout << aggressiveCow(Stall , K);

    return 0;
}