#include<iostream>
#include<vector>    
using namespace std;

void printArray(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

// jo answer aayega usko reverse krna hoga - RHS ke respective mai banane ke liye
vector<int> reverse(vector<int> v){
    int s = 0;
    int e = v.size()-1;
    while (s<e)
    {
        swap(v[s++]  , v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int> &a, int n, vector<int>&b, int m){
    int i = n-1;
    int j = m-1;

    vector<int> ans;

    int carry = 0;

    while (i>=0 && j>=0)
    {
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum % 10;
        // isko ans waale array mai daal diya 
        ans.push_back(sum);
        i--;
        j--;
    }

    // ab wo 3 case handle kr lete hai
    // 1st case
    while (i>=0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    
    // 2nd case
    while (j>=0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // 3rd case
    while (carry != 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    
    // print ans
    return reverse(ans);
}

int main(){

    vector<int> a = {1,2,3,4};
    vector<int> b = {6};
    
    vector<int> ans =  findArraySum(a,4,b,1);
    printArray(ans);
    
    return 0;
}