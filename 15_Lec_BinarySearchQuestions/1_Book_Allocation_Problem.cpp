#include<iostream>
using namespace std;

bool isPossible(int arr[] , int n , int m , int mid){
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            
        }        
    }
    return true;
}

int allocatedBook(int arr[] , int n , int m){
    int i = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int j = sum;
    int mid = i + (j - i) / 2;
    int ans = -1;

    while (i <= j)
    {
        if (isPossible(arr,n,m,mid))
        {   
            ans = mid;
            j = mid - 1;
        }
        else{
            i = mid + 1;
        } 
        mid = i + (j - i) / 2;       
    }
    return mid;
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

    int n;
    cout << "Enter total number books : ";
    cin >> n;

    int m;
    cout << "Enter total number pages : ";
    cin >> m;

    cout << allocatedBook(arr,n,m);

    return 0;
}