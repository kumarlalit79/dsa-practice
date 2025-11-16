#include<iostream>
#include<vector>    
using namespace std;

void printArray(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr1[], int n, int arr2[], int m, int arr3[]){

    int i = 0; // arr1 ka 0th index 
    int j = 0; // arr2 ka 0th index
    int k = 0; // 3rd array ko track krne ke liye le liya. 3rd array ke 0th index se shuru krne ke liye

    // pehle dono arry ko sath leke chal re ki, 1st bhi khtm ni hona chahiye and 2nd bhi
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i]; // 3rd array ke andr chhoti value daal di
            k++; // 0th index pe to value dal gayi, ab aage badhao
            i++;
        }
        else{
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    
    // agr first array mai element bach jaye to use copy krdo
    while (i<n)
    {
        arr3[k] = arr1[i]; // copy kr diya as it is arr3 mai
        k++;
        i++;
    }

    // agr second array mai element bach jaye to use copy krdo
    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

int main(){
    
    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};

    int arr3[8] = {0}; //starting mai isme 0 pada hoga, and 5+3=8 size ka ye array hoga
    
    merge(arr1,5,arr2,3,arr3);
    printArray(arr3,8);
    
    return 0;
}