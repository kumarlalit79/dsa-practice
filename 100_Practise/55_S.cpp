#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> smallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;

}

int main(){

    vector<int> arr = {6, 8, 0, 1,3};
    int n = arr.size();

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> result = smallerElement(arr, n);

    cout << "Next Smaller Elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}