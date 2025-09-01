#include<iostream>
using namespace std;

int partation(int arr[] , int s , int e){

    // pivot nikaal lo sbse pehle
    int pivot = arr[s];

    // count krlo kitne number chhote hai pivot se
    int count = 0;
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    
    // pivot ko sahi position pe daalo
    int pivotRightIndex = s + count;
    swap(arr[pivotRightIndex] , arr[s]);

    // pivot right position pe hai, ab bas left(less than pivot) or right(greater than pivot) part sambhalna hai
    int i = s, j = e; // 2 pointer hamne laga diye
    
    while (i < pivotRightIndex && j > pivotRightIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotRightIndex && j > pivotRightIndex)
        {
            swap(arr[i++] , arr[j--]);
        }
        
    }
    
    return pivotRightIndex;
}

void quickSort(int arr[] , int s , int e){

    // base case
    if(s >= e)
        return;

    // partation krlo
    int p = partation(arr , s , e);

    // left part sort karo
    quickSort(arr , s , p-1);

    // right part sort karo
    quickSort(arr, p+1, e);

}

int main(){
    
    int arr[9] = {3,1,2,4,1,5,2,6,4};
    int n = 9;

    int s = 0;
    int e = n-1;
    
    quickSort(arr, s , e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}