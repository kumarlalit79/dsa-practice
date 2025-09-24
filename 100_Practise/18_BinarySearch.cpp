#include<iostream>
using namespace std;

bool BS(int arr[] , int s , int e ,int size , int key){

    if (s > e)
    {
        return false;
    }
    
    int mid = s + (e-s) / 2;

    if (arr[mid] == key)
    {
        return true;
    }
    
    if (arr[mid] > key)
    {
        BS(arr,s,mid-1,size,key);
    }
    else{
        BS(arr,mid+1,e,size,key);
    }

}

int main(){

    int arr[6] = {122,4,6,10,14,18};

    int key = 75;
    int s = 0;
    int e = 5;
    int check = BS(arr,s,e,6,key);

    if (check)
    {
        cout << "Present" ;
    }
    else{
        cout << "Not";
    }

    return 0;
}