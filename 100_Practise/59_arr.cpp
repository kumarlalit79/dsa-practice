#include<iostream>
using namespace std;

bool linearSearch(int arr[] , int size , int key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
        
    }
    return false;
}

int main(){

    int arr[100];

    int size;
    cout << "Enter the size of the array  : " << endl;
    cin >> size;

    

    cout << "Enter the elemets of the array  : " << endl;
    for (int i = 0; i < size-1; i++)
    {
        cin >> arr[i];
    }
    
    int key;
    cout << "Enter key : " << endl;
    cin >> key;

    bool check = linearSearch(arr, size , key);
    if (check)
    {
        cout << "Present" << endl;
    }
    else{
        cout << "Not Present" << endl;
    }
    
    return 0;
}