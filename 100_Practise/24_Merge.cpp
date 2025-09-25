#include<iostream>
using namespace std;

void merge(int *arr, int s , int e){
    int mid = s + (e-s) / 2;

    // calculating length of left array
    int len1 = mid - s + 1;
    cout << "length 1  " << len1 << endl;

    // calculating length of right array
    int len2 = e - mid;
    cout << "length 2 " << len2 << endl;

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

    // dono array ke element compare karke original array me store karte rahenge
    while (index1 < len1 && index2 < len2)
    {
        // agar first array ka current element chhota hai to wo daal do original array me
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];  // element copy karo, index1++ means next element pe move ho jao
        }
        else{
            arr[mainArrayIndex++] = second[index2++]; // warna second array ka element chhota hai to wo daal do
        }
    }
    
    // agar first array ke elements bache hain to unhe copy kar do
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];  // baaki bachhe huye element daal do
    }

    // agar second array ke elements bache hain to unhe copy kar do
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++]; // baaki bachhe huye element daal do
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
    
    int arr[5] = {2,5,1,6,9};
    int n = 5;

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