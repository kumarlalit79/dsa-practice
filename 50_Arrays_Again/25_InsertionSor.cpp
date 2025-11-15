#include<iostream>
#include<vector>    
using namespace std;

void printArray(vector<int> &arr , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertionSort(vector<int> &arr , int size){

    // loop for round waali game 
    for (int i = 0; i < size; i++)
    {
        // 0th index ki value ko kahi store krlo cuz hamne wo sorted mana hai
        int temp = arr[i];

        // ab har ith index ko i-1th index se compare karwa re
        // so j waala loop mera i-1 index se 0 tak chal raha hoga, cuz ham peeche ki trh jaare the
        int j = i-1;
        for (; j >= 0; j--)
        {
            // right shift ke liye, aaghe waale element ko copy kr dunga
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                // agar temp se badi value aa jaye, to break kar jao
                break;
            }
        }
        arr[j+1] =  temp; // jab do element ke beech mai daalna hoga
    }
}


// this code will look more clean with while loop
void insertionSortWhile(vector<int> &arr , int size){

    for (int i = 1; i < size; i++) {

        int temp = arr[i];
        int j = i - 1;

        // shift elements to the right
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }

        // insert in correct position
        arr[j+1] = temp;
    }
}

int main(){
        
    vector<int> arr = {64,25,12,22,11};
    insertionSort(arr , 5);
    printArray(arr,5);
    insertionSortWhile(arr , 5);
    printArray(arr,5);
    return 0;
}