#include<iostream>
using namespace std;

// Function to find the pivot (smallest element's index)
int getPivot(int arr[], int size) {
    int i = 0, j = size - 1;
    int mid = i + (j - i) / 2;

    while (i < j) {
        if (arr[mid] >= arr[0]) {
            i = mid + 1;
        } else {
            j = mid;
        }
        mid = i + (j - i) / 2;
    }
    return i;
}

// Standard binary search
int binarySearch(int arr[], int i, int j, int key) {
    int start = i, end = j;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

// Function to find the key's position
int findPosition(int arr[], int size, int key) {
    int pivot = getPivot(arr, size);

    if (key >= arr[pivot] && key <= arr[size - 1]) {
        return binarySearch(arr, pivot, size - 1, key);
    } else {
        return binarySearch(arr, 0, pivot - 1, key);
    }
}   

int main() {
    int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];
    cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key: ";
    cin >> key;

    int position = findPosition(arr, size, key);

    if (position != -1)
        cout << "Key found at index: " << position << endl;
    else
        cout << "Key not found in the array." << endl;

    return 0;
}
