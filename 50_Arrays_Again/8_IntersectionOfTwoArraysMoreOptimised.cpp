#include<iostream>
#include<vector>
#include <limits.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1 , int n , vector<int> &arr2 , int m){

    int i = 0 , j = 0;
    vector<int> ans;
    
    while (i<n && j<m) // jab tk i and j apni range mai hai
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}

int main(){

    vector<int> arr1 = {1,2,3};
    int n = 3;
    vector<int> arr2 = {2,3,4};
    int m = 2;

    vector<int> result =  findArrayIntersection(arr1 , n , arr2 , m);
    cout << "Intersection elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
 
    return 0;
}