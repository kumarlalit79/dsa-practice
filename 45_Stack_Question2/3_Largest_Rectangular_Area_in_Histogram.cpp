#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;


// peeche ye function values ke aadhar pe likha tha, ab ye index ke hisab se likhna hoga
vector<int> nextSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1); 

    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) // yaha value ko value se compare karo
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i); // value ki jgh yaha index push karo
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1); 

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) // yaha value ko value se compare karo
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i); // value ki jgh yaha index push karo
    }
    return ans;
}


int largestRectangleArea(vector<int> &height){

    int n = height.size();

    vector<int> next(n); 
    next = nextSmallerElement(height , n); 

    vector<int> prev(n); 
    prev = prevSmallerElement(height , n); 

    int maxArea  = INT_MIN;

    for(int i=0; i<n; i++){
        // yaha area calculate kr lunga
        int length = height[i];
        
        
        // handling width = -1 case. If no next smaller element exists, treat it as n (out of bound index)
        if (next[i] == -1)
        {
            next[i] = n;
        }

        int breadth = next[i] - prev[i] - 1;
        int newArea = length * breadth;
        maxArea  = max(maxArea  , newArea); 
    }
    return maxArea;

}

int main(){
    vector<int> histogram = {2, 1, 5, 6, 2, 3};

    cout << "Histogram Heights: ";
    for (int h : histogram) cout << h << " ";
    cout << endl;

    int result = largestRectangleArea(histogram);
    cout << "Largest Rectangle Area = " << result << endl;

    return 0;
}