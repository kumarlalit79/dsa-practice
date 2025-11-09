#include<iostream>
#include<vector>
#include <limits.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1 , int n , vector<int> &arr2 , int m){

    vector<int> ans;
    
    // traversing arr1
    for (int i = 0; i < n; i++)
    {
        int element = arr1[i];

        
        

        // ab arr1 ko arr2 se compare karwaana hai
        for (int j = 0; j < m; j++)
        {
            if (element < arr2[j])
                break;
                
            if (element == arr2[j])
            {
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
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