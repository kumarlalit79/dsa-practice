#include<iostream>
using namespace std;

int binarySearch(int arr[] , int size , int key){
    
    int start = 0;
    int end = size-1;

    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        
        if (key > arr[mid]) // to right mai jao
        {
            start = mid + 1;
        }
        else{ // warna left part mai jao
            end = mid - 1;
        }

        // maine upper start or end lo update kr diya hai to ab mujhe mid ko bhi update karna hoga
        mid = (start + end) / 2;
    }
    return -1;
}

int main(){

    int evenArr[6] = {2,4,6,8,12,18};
    int oddArr[5] = {3,8,11,14,16};

    cout << "Index of key is " << binarySearch(evenArr , 6 , 12) << endl;
    cout << "Index of key is " << binarySearch(oddArr , 5 , 11);

    return 0;
}