#include<iostream>
using namespace std;

int fistOccurence(int arr[] , int size, int key){

    int i = 0, j = size - 1;
    int mid = i + (j - i) / 2;
    int ans = -1;
    while (i <= j)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            j = mid - 1;
        }
        else if (key > arr[mid]) // right mai jana hai
        {
            i = mid + 1;
        }
        else if (key < arr[mid]) // left mai jana hai
        {
            j = mid - 1;
        }

        mid = i + (j - i) / 2;
    }

    
    return ans;
}

int lastOccurence(int arr[] , int size, int key){

    int i = 0, j = size - 1;
    int mid = i + (j - i) / 2;
    int ans = -1;
    while (i <= j)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            i = mid + 1;
        }
        else if (key > arr[mid]) // right mai jana hai
        {
            i = mid + 1;
        }
        else if (key < arr[mid]) // left mai jana hai
        {
            j = mid - 1;
        }

        mid = i + (j - i) / 2;
    }
    return ans;

}

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];

    cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key : ";
    cin >> key;

    int total = (lastOccurence(arr , size , key) - fistOccurence(arr , size , key)) + 1;
    cout << "Total number of occurence : " << total;
}