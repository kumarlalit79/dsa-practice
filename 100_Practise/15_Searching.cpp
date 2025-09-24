#include<iostream>
using namespace std;

bool sorting(int arr[] , int size){
    
    if (size == 0 || size == 1)
    {
        return true;
    }
    
    if (arr[0] > arr[1])
    {
        return false;
    }
    else{
        bool check = sorting(arr+1 , size-1);
        return check;
    }

}

int main(){

    int arr[5] = {11,222,3,4,5};
    int ans = sorting(arr , 5);
    if (ans)
    {
        cout << "sorted";
    }
    else{
        
        cout << "un sorted";
    }
    
}