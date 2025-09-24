#include<iostream>
using namespace std;

bool LS(int arr[] , int size , int key){

    if (size == 0)
    {
        return false;
    }
    
    if (arr[0] == key)
    {
        return true;
    }
    else{
        return LS(arr+1 , size-1 , key);
    }

}

int main(){

    int arr[5] = {1,2,3,4,5};

    int key = 75;
    int check = LS(arr,5,key);

    if (check)
    {
        cout << "Present" ;
    }
    else{
        cout << "Not";
    }

    return 0;
}