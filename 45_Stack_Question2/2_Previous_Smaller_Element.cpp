#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> previousSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1); // initially no smaller element

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {  // NOTE: left → right traversal
        int curr = arr[i];
        while (s.top() >= curr) {
            s.pop();
        }
        ans[i] = s.top(); // top is previous smaller
        s.push(curr);
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    int n = arr.size();

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    vector<int> result = previousSmallerElement(arr, n);

    cout << "Previous Smaller Elements: ";
    for (int i = 0; i < n; i++) cout << result[i] << " ";
    cout << endl;

    return 0;
}
