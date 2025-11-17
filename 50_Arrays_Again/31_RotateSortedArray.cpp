#include<iostream>
#include<vector>    
using namespace std;

bool rotateSortedArray(vector<int> &arr){

    int count = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i-1] > arr[i]) // peeche waale element ko aage waale se compare karna hai
        {
            count++; // pair exist krta h to count++ kr dega ye
        }
        
    }
    // last cyclic comparision ke liye - last element ko 1st element se
    if (arr[n-1] > arr[0])
    {
        count++; 
    }
    return count<=1; // 1 hai to true krdo warna false
    
}

int main(){
    
    vector<int> arr = {3,4,5,1,2};
    bool check = rotateSortedArray(arr);
    if (check)
    {
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}