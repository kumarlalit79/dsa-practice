#include<iostream>
using namespace std;

void merge(int *arr, int s , int e){
    int mid = s + (e-s) / 2;

    // calculating length of left array
    int len1 = mid - s + 1;

    // calculating length of right array
    int len2 = e - mid;

    // 2 new array bana diya jisme copy karenge-dynamic memory allocation
    int *first = new int[len1];
    int *second = new int[len2];

    // copying value from above to below
    // first array pe copy krdi
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayIndex++];
    } 

    // second array pe copy krdi
    mainArrayIndex = mid + 1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    } 

    // merging 2 sorted array
    int index1 = 0;// first array ka index
    int index2 = 0;// second array ka index
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    
    // deleting, cuz inka kaam yaha pe khtm ho gaya
    delete []first;
    delete []second;
    

}

void mergeSort(int *arr, int s , int e){
    // base case 
    if(s >= e){
        return ;
    }
    
    // RR

    int mid = s + (e-s) / 2;
    // left part sorting
    mergeSort(arr , s , mid);

    // right part sorting
    mergeSort(arr , mid+1 , e);

    // merging both part
    merge(arr, s,e);
    
}

int main(){
    
    int arr[9] = {3,1,2,4,1,5,2,6,4};
    int n = 9;

    int s = 0;
    int e = n-1;
    mergeSort(arr, s , e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}