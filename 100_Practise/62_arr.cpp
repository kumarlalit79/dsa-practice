#include<iostream>
using namespace std;

int findUnique(int arr[] , int size){

    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    
    return ans;

}

int main(){

    int arr[7] = {2,3,9,6,3,6,2};
    cout << "Unique element is : " << findUnique(arr,7); 
        
    return 0;
}