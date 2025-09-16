#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1); // starting mai hi stack mai -1 daal diya

    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr) // jab tak chhota element nahi milta pop krte jao
        {
            s.pop();
        }
        // loop se bahar aa gaye that means answer is stack ka top.
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main() {
    // Example array (input manually set kiya)
    vector<int> arr = {2, 1, 4, 3};
    int n = arr.size();

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next Smaller Elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
